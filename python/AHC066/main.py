"""AHC066 解答 — v1: BFS 順次運搬（マクロ未使用の素朴解）。

戦略:
  各ボール k について「現在地→ball[k] を BFS 最短路で移動→S で拾う→
  basket[k] へ BFS 最短路で移動→S で置く」を順に行う。
  生成したボタン列が T を超えそうなら、そのボールはスキップして次へ進む
  （置けるボールを最大化＝スコア T*(M-V) の V を増やす）。

スコアは「全完了ならボタン数 / 未完なら T*(M-V)」で小さいほど良い。
このv1はマクロ(M/P)を使わないため、まず確実に動く土台。圧縮はここから改善する。
"""

from __future__ import annotations

import sys
from collections import deque

DIJ: list[tuple[int, int]] = [(-1, 0), (0, 1), (1, 0), (0, -1)]  # U,R,D,L
# (di,dj) -> 向きインデックス の逆引き
DIR_OF: dict[tuple[int, int], int] = {d: i for i, d in enumerate(DIJ)}


def read_input() -> tuple[
    int,
    int,
    int,
    list[list[bool]],
    list[list[bool]],
    list[tuple[int, int]],
    list[tuple[int, int]],
]:
    lines = sys.stdin.read().split("\n")
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
    return n, m, t, wall_v, wall_h, balls, baskets


def solve(
    n: int,
    m: int,
    t: int,
    wall_v: list[list[bool]],
    wall_h: list[list[bool]],
    balls: list[tuple[int, int]],
    baskets: list[tuple[int, int]],
) -> list[str]:
    def can_move(i: int, j: int, d: int) -> bool:
        di, dj = DIJ[d]
        i2, j2 = i + di, j + dj
        if not (0 <= i2 < n and 0 <= j2 < n):
            return False
        if di == 0:
            return not wall_v[i][min(j, j2)]
        return not wall_h[min(i, i2)][j]

    def bfs_path(
        src: tuple[int, int], dst: tuple[int, int]
    ) -> list[tuple[int, int]] | None:
        """src から dst までの最短路（マス列、src を含む）。到達不能なら None。"""
        if src == dst:
            return [src]
        prev: dict[tuple[int, int], tuple[int, int] | None] = {src: None}
        q: deque[tuple[int, int]] = deque([src])
        while q:
            i, j = q.popleft()
            for d in range(4):
                if not can_move(i, j, d):
                    continue
                di, dj = DIJ[d]
                nb = (i + di, j + dj)
                if nb in prev:
                    continue
                prev[nb] = (i, j)
                if nb == dst:
                    path = [nb]
                    cur: tuple[int, int] | None = (i, j)
                    while cur is not None:
                        path.append(cur)
                        cur = prev[cur]
                    path.reverse()
                    return path
                q.append(nb)
        return None

    def cells_to_buttons(
        path: list[tuple[int, int]], cur_dir: int
    ) -> tuple[list[str], int]:
        """マス列を、回転(R/L)+前進(F) のボタン列へ符号化する。"""
        out: list[str] = []
        d = cur_dir
        for a, b in zip(path, path[1:]):
            nd = DIR_OF[(b[0] - a[0], b[1] - a[1])]
            diff = (nd - d) % 4
            if diff == 1:
                out.append("R")
            elif diff == 2:
                out.append("R")
                out.append("R")
            elif diff == 3:
                out.append("L")
            out.append("F")
            d = nd
        return out, d

    ops: list[str] = []
    p: tuple[int, int] = (0, 0)
    cur_dir = 1  # 開始は右向き

    for k in range(m):
        path1 = bfs_path(p, balls[k])
        if path1 is None:
            continue
        b1, d1 = cells_to_buttons(path1, cur_dir)
        path2 = bfs_path(balls[k], baskets[k])
        if path2 is None:
            continue
        b2, d2 = cells_to_buttons(path2, d1)
        seg = b1 + ["S"] + b2 + ["S"]
        if len(ops) + len(seg) <= t:
            ops += seg
            p = baskets[k]
            cur_dir = d2
        # 入らなければスキップして次のボールへ
    return ops


def main() -> None:
    n, m, t, wall_v, wall_h, balls, baskets = read_input()
    ops = solve(n, m, t, wall_v, wall_h, balls, baskets)
    sys.stdout.write("".join(ops) + "\n")


if __name__ == "__main__":
    main()
