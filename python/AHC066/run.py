"""AHC066 一括実行 & 採点スクリプト。

tools/in/ の各入力に対して main.py を実行し、出力を out/ に保存、scorer.py で採点する。
seed 別のスコア・V・有効性と、合計／平均を表示する。

使い方:
    python run.py                 # tools/in の全ケース
    python run.py 0 9             # seed 0..9
    python run.py 0-99            # seed 0..99（範囲指定）
    python run.py 0,5,10          # 個別指定
    python run.py --jobs 1        # 直列実行（デバッグ用）
    python run.py --cmd "python main.py"   # 実行コマンドを差し替え

スコアは小さいほど良い。無効出力(INVALID)は明確に表示し、合計には
最悪相当のペナルティ T*M を計上する（無効を「0で最良」と誤認しないため）。
"""

from __future__ import annotations

import argparse
import glob
import os
import shlex
import subprocess
import sys
from concurrent.futures import ProcessPoolExecutor
from dataclasses import dataclass

from scorer import Input, compute_score, parse_input, parse_output

IN_DIR = "tools/in"
OUT_DIR = "out"


@dataclass
class Result:
    seed: int
    n: int
    m: int
    t: int
    v: int
    score: int
    err: str
    n_ops: int
    elapsed: float


def parse_seed_arg(tokens: list[str]) -> list[int]:
    """位置引数を seed のリストに変換する。空なら in ディレクトリの全 seed。"""
    if not tokens:
        seeds = []
        for path in sorted(glob.glob(os.path.join(IN_DIR, "*.txt"))):
            name = os.path.splitext(os.path.basename(path))[0]
            if name.isdigit():
                seeds.append(int(name))
        return seeds
    if len(tokens) == 2 and all(t.isdigit() for t in tokens):
        lo, hi = int(tokens[0]), int(tokens[1])
        return list(range(lo, hi + 1))
    seeds: list[int] = []
    for tok in tokens:
        for part in tok.split(","):
            part = part.strip()
            if not part:
                continue
            if "-" in part:
                lo, hi = part.split("-")
                seeds.extend(range(int(lo), int(hi) + 1))
            else:
                seeds.append(int(part))
    return seeds


def run_one(args: tuple[int, list[str]]) -> Result:
    import time

    seed, cmd = args
    in_path = os.path.join(IN_DIR, f"{seed:04d}.txt")
    out_path = os.path.join(OUT_DIR, f"{seed:04d}.txt")
    with open(in_path, encoding="utf-8") as f:
        in_text = f.read()
    inp: Input = parse_input(in_text)

    # 解答プロセスを起動。タイムアウト/例外は握りつぶして「最悪相当(T*M)」の
    # ペナルティ計上に乗せる（バッチ全体をクラッシュさせない）。
    start = time.perf_counter()
    try:
        proc = subprocess.run(
            cmd,
            input=in_text,
            capture_output=True,
            text=True,
            timeout=60,
        )
    except subprocess.TimeoutExpired:
        elapsed = time.perf_counter() - start
        return Result(seed, inp.N, inp.M, inp.T, 0, 0, "timeout(>60s)", 0, elapsed)
    except Exception as e:  # noqa: BLE001 起動失敗等も無効扱いで集計を守る
        elapsed = time.perf_counter() - start
        return Result(
            seed, inp.N, inp.M, inp.T, 0, 0, f"run error: {type(e).__name__}", 0, elapsed
        )
    elapsed = time.perf_counter() - start
    out_text = proc.stdout

    os.makedirs(OUT_DIR, exist_ok=True)
    with open(out_path, "w", encoding="utf-8") as f:
        f.write(out_text)

    # 解答が異常終了(非ゼロ)した場合は INVALID 扱い。INCOMPLETE に紛れさせない。
    if proc.returncode != 0:
        err = (proc.stderr or "").strip().replace("\n", " ")[:120]
        return Result(
            seed, inp.N, inp.M, inp.T, 0, 0, f"exit {proc.returncode}: {err}", 0, elapsed
        )

    ops, perr = parse_output(inp, out_text)
    if perr:
        return Result(seed, inp.N, inp.M, inp.T, 0, 0, perr, len(ops), elapsed)
    score, serr, v = compute_score(inp, ops)
    return Result(seed, inp.N, inp.M, inp.T, v, score, serr, len(ops), elapsed)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("seeds", nargs="*", help="seed 範囲/リスト（省略時は全件）")
    ap.add_argument("--cmd", default="python main.py", help="解答の実行コマンド")
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    args = ap.parse_args()

    cmd = shlex.split(args.cmd)
    seeds = parse_seed_arg(args.seeds)
    if not seeds:
        print("対象 seed がありません（tools/in を確認）", file=sys.stderr)
        raise SystemExit(1)

    tasks = [(s, cmd) for s in seeds]
    results: list[Result] = []
    if args.jobs <= 1:
        results = [run_one(t) for t in tasks]
    else:
        with ProcessPoolExecutor(max_workers=args.jobs) as ex:
            results = list(ex.map(run_one, tasks))
    results.sort(key=lambda r: r.seed)

    print(f"{'seed':>4} {'N':>3} {'M':>3} {'T':>7} {'V':>3} {'score':>9} "
          f"{'ops':>6} {'sec':>5}  note")
    total = 0
    n_complete = 0
    n_invalid = 0
    worst: list[Result] = []
    for r in results:
        if r.err:
            note = f"INVALID: {r.err}"
            n_invalid += 1
            effective = r.t * r.m  # 無効は最悪相当でペナルティ
        else:
            complete = r.v == r.m
            note = "complete" if complete else f"INCOMPLETE {r.v}/{r.m}"
            if complete:
                n_complete += 1
            effective = r.score
        total += effective
        print(f"{r.seed:>4} {r.n:>3} {r.m:>3} {r.t:>7} {r.v:>3} {r.score:>9} "
              f"{r.n_ops:>6} {r.elapsed:>5.2f}  {note}")
        worst.append(r)

    n = len(results)
    print("-" * 60)
    print(f"cases     : {n}")
    print(f"complete  : {n_complete}/{n}")
    print(f"incomplete: {n - n_complete - n_invalid}/{n}")
    print(f"invalid   : {n_invalid}/{n}")
    print(f"total     : {total}")
    print(f"average   : {total / n:.1f}")

    # 改善余地の大きい（スコアの高い）上位ケースを表示
    worst.sort(key=lambda r: (r.t * r.m if r.err else r.score), reverse=True)
    print("worst 5   : " + ", ".join(
        f"seed{r.seed}({(r.t * r.m if r.err else r.score)})" for r in worst[:5]
    ))


if __name__ == "__main__":
    main()
