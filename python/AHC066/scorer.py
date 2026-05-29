"""AHC066 のローカル採点器。

tools/src/lib.rs のシミュレータ・スコア計算を Python へ厳密移植したもの。
Rust(cargo) を入れずにローカルで採点ループを回すために使う。
run.py から import するほか、CLI 採点にも使える:

    python scorer.py tools/in/0000.txt out/0000.txt
"""

from __future__ import annotations

import sys
from collections import deque
from dataclasses import dataclass

# 向き: 0:U, 1:R, 2:D, 3:L （lib.rs の DIJ と一致）
DIJ: list[tuple[int, int]] = [(-1, 0), (0, 1), (1, 0), (0, -1)]
BUTTONS: frozenset[str] = frozenset("FRLSMP")
BASIC: frozenset[str] = frozenset("FRLS")


@dataclass
class Input:
    """入力 1 ケース分。lib.rs の struct Input と同じ意味。"""

    N: int
    M: int
    T: int
    wall_v: list[list[bool]]  # N x (N-1): (i,j) と (i,j+1) の間の壁
    wall_h: list[list[bool]]  # (N-1) x N: (i,j) と (i+1,j) の間の壁
    balls: list[tuple[int, int]]
    baskets: list[tuple[int, int]]


def parse_input(text: str) -> Input:
    """入力テキストを Input に変換する。"""
    lines = text.split("\n")
    n, m, t = (int(x) for x in lines[0].split())
    idx = 1
    wall_v = [[c == "1" for c in lines[idx + i].strip()] for i in range(n)]
    idx += n
    wall_h = [[c == "1" for c in lines[idx + i].strip()] for i in range(n - 1)]
    idx += n - 1
    balls: list[tuple[int, int]] = []
    baskets: list[tuple[int, int]] = []
    for i in range(m):
        b, c, d, e = (int(x) for x in lines[idx + i].split())
        balls.append((b, c))
        baskets.append((d, e))
    return Input(N=n, M=m, T=t, wall_v=wall_v, wall_h=wall_h, balls=balls, baskets=baskets)


def parse_output(inp: Input, text: str) -> tuple[list[str], str]:
    """出力テキストをボタン列に変換する。lib.rs の parse_output と同じ検査。

    戻り値は (ops, err)。err が空でなければ無効出力。
    """
    ops: list[str] = []
    for token in text.split():
        for c in token:
            if c not in BUTTONS:
                return [], f"Invalid operation: {c}"
            ops.append(c)
    if len(ops) > inp.T:
        return ops, f"Too many button operations: {len(ops)} > {inp.T}"
    return ops, ""


def can_move(inp: Input, pos: tuple[int, int], d: int) -> bool:
    """マス pos から向き d に進めるか（壁・盤外判定）。"""
    i, j = pos
    di, dj = DIJ[d]
    i2, j2 = i + di, j + dj
    if not (0 <= i2 < inp.N and 0 <= j2 < inp.N):
        return False
    if di == 0:
        return not inp.wall_v[i][min(j, j2)]
    return not inp.wall_h[min(i, i2)][j]


def next_pos(inp: Input, pos: tuple[int, int], d: int) -> tuple[int, int]:
    if not can_move(inp, pos, d):
        return pos
    di, dj = DIJ[d]
    return (pos[0] + di, pos[1] + dj)


def expand_output(inp: Input, ops: list[str]) -> list[str]:
    """生ボタン列を基本操作列(F/R/L/S)へ展開する。lib.rs の expand_output と同じ。

    M でマクロ記録のトグル、P で直近マクロを再生。展開長は T で打ち切る。
    """
    expanded: list[str] = []
    last_macro: list[str] = []
    cur_macro: list[str] = []
    recording = False
    for c in ops:
        if len(expanded) >= inp.T:
            break
        if c in BASIC:
            expanded.append(c)
            if recording:
                cur_macro.append(c)
        elif c == "M":
            if recording:
                last_macro = cur_macro[:]
                cur_macro = []
                recording = False
            else:
                cur_macro = []
                recording = True
        elif c == "P":
            for b in last_macro:
                if len(expanded) >= inp.T:
                    break
                expanded.append(b)
                if recording:
                    cur_macro.append(b)
    return expanded


class Sim:
    """ボタン列を実行するシミュレータ。lib.rs の Sim と同じ状態遷移。"""

    def __init__(self, inp: Input, ops: list[str]) -> None:
        self.inp = inp
        self.balls: list[list[int | None]] = [[None] * inp.N for _ in range(inp.N)]
        for k, (i, j) in enumerate(inp.balls):
            self.balls[i][j] = k
        self.basic_turn = 0
        self.p: tuple[int, int] = (0, 0)
        self.dir = 1  # 開始は右向き
        self.hand: int | None = None
        self.expanded = expand_output(inp, ops)

    def step_basic(self, op: str) -> None:
        if op == "F":
            self.p = next_pos(self.inp, self.p, self.dir)
        elif op == "R":
            self.dir = (self.dir + 1) % 4
        elif op == "L":
            self.dir = (self.dir + 3) % 4
        elif op == "S":
            i, j = self.p
            self.hand, self.balls[i][j] = self.balls[i][j], self.hand
        self.basic_turn += 1

    def run_until(self, t: int) -> None:
        limit = min(t, len(self.expanded), self.inp.T)
        while self.basic_turn < limit:
            self.step_basic(self.expanded[self.basic_turn])

    def count_correct(self) -> int:
        v = 0
        for k, (i, j) in enumerate(self.inp.baskets):
            if self.balls[i][j] == k:
                v += 1
        return v


def compute_score(inp: Input, ops: list[str]) -> tuple[int, str, int]:
    """スコアを計算する。lib.rs の compute_score 相当。

    戻り値 (score, err, V)。
    - err が空でなければ無効（score は 0）。
    - V == M（全完了）なら score = ボタン数、そうでなければ score = T*(M-V)。
    - スコアは小さいほど良い。
    """
    if len(ops) > inp.T:
        return 0, f"Too many button operations: {len(ops)} > {inp.T}", 0
    sim = Sim(inp, ops)
    sim.run_until(inp.T)
    v = sim.count_correct()
    if v == inp.M:
        score = len(ops)
    else:
        score = inp.T * (inp.M - v)
    return score, "", v


def score_files(in_path: str, out_path: str) -> tuple[int, str, int]:
    with open(in_path, encoding="utf-8") as f:
        inp = parse_input(f.read())
    with open(out_path, encoding="utf-8") as f:
        out_text = f.read()
    ops, perr = parse_output(inp, out_text)
    if perr:
        return 0, perr, 0
    return compute_score(inp, ops)


def main() -> None:
    if len(sys.argv) != 3:
        print("usage: python scorer.py <in.txt> <out.txt>", file=sys.stderr)
        raise SystemExit(2)
    score, err, v = score_files(sys.argv[1], sys.argv[2])
    if err:
        print(f"INVALID: {err}")
        print(f"Score = 0")
    else:
        print(f"V = {v}")
        print(f"Score = {score}")


if __name__ == "__main__":
    main()
