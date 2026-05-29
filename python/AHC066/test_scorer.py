"""scorer.py（lib.rs の Python 移植）の挙動を手計算した期待値で検証するテスト。

ジャッジの心臓部なので、ここはコードに依存せず手で計算した値を期待値に置く。
pytest でも `python test_scorer.py` でも実行できる。
"""

from scorer import Input, parse_output, expand_output, compute_score


def no_walls(n: int) -> tuple[list[list[bool]], list[list[bool]]]:
    """壁のない N×N グリッドの (wall_v, wall_h) を返す。"""
    wall_v = [[False] * (n - 1) for _ in range(n)]
    wall_h = [[False] * n for _ in range(n - 1)]
    return wall_v, wall_h


def make_input(
    n: int,
    m: int,
    t: int,
    balls: list[tuple[int, int]],
    baskets: list[tuple[int, int]],
    wall_v: list[list[bool]] | None = None,
    wall_h: list[list[bool]] | None = None,
) -> Input:
    if wall_v is None or wall_h is None:
        wall_v, wall_h = no_walls(n)
    return Input(
        N=n, M=m, T=t, wall_v=wall_v, wall_h=wall_h, balls=balls, baskets=baskets
    )


def test_basic_move_swap_and_score() -> None:
    # N=2、壁なし。ロボットは (0,0) 向き右で開始。
    # ball0 を (0,1) で拾い、(1,0) のカゴへ運ぶ。
    # F:(0,0)->(0,1)  S:拾う  R:右(下向き)  F:(1,1)  R:右(左向き)  F:(1,0)  S:置く
    inp = make_input(2, 1, 100, balls=[(0, 1)], baskets=[(1, 0)])
    ops = list("FSRFRFS")
    score, err, v = compute_score(inp, ops)
    assert err == "", err
    assert v == 1
    assert score == 7  # 完了したのでボタン数がスコア


def test_macro_expand_simple() -> None:
    # "M F M P P" -> マクロ [F] を登録して 2 回再生。展開は F,F,F の 3 個。
    inp = make_input(3, 0, 100, balls=[], baskets=[])
    ops = list("MFMPP")
    assert expand_output(inp, ops) == list("FFF")
    score, err, v = compute_score(inp, ops)
    assert err == ""
    assert v == 0  # M=0 なので全完了扱い
    assert score == len(ops)  # = 5（生ボタン数）


def test_macro_record_during_replay() -> None:
    # 再生(P)中の基本操作も記録中マクロに積まれることの確認。
    # M F M  -> last=[F]
    # M      -> 記録開始
    # P      -> [F] を再生（exp に F、cur に F）
    # M      -> last=cur=[F]
    # P      -> [F] を再生
    # 展開は F,F,F。
    inp = make_input(3, 0, 100, balls=[], baskets=[])
    ops = list("MFMMPMP")
    assert expand_output(inp, ops) == list("FFF")


def test_incomplete_score_formula_v0() -> None:
    # 何もしない -> V=0 -> score = T*(M-V) = 50*2 = 100
    inp = make_input(3, 2, 50, balls=[(0, 0), (2, 2)], baskets=[(0, 1), (2, 1)])
    score, err, v = compute_score(inp, [])
    assert err == ""
    assert v == 0
    assert score == 50 * 2


def test_incomplete_score_formula_v1() -> None:
    # ball0 が最初からカゴ0 の上にある退化入力。何もせず V=1 -> score = T*(2-1) = 50
    inp = make_input(3, 2, 50, balls=[(0, 1), (2, 2)], baskets=[(0, 1), (2, 1)])
    score, err, v = compute_score(inp, [])
    assert err == ""
    assert v == 1
    assert score == 50 * 1


def test_too_many_ops_is_error() -> None:
    inp = make_input(2, 1, 3, balls=[(0, 1)], baskets=[(1, 0)])
    ops, perr = parse_output(inp, "FFFF")  # 4 > T=3
    assert "Too many" in perr
    score, err, v = compute_score(inp, ops)
    assert err != ""
    assert score == 0  # 無効出力は score 0（＝相対順位では最下位）


def test_invalid_char_is_error() -> None:
    inp = make_input(2, 1, 100, balls=[(0, 1)], baskets=[(1, 0)])
    ops, perr = parse_output(inp, "FXF")
    assert "Invalid operation" in perr


def test_expanded_capped_at_T_during_replay() -> None:
    # macro=[F,F,F] を記録(=3基本操作) し、P を 3 回。
    # 生ボタン: M F F F M P P P = 8 <= T=10（有効）
    # 展開: 記録3 + 3 + 3 + (4個目で打ち切り) = 10 で T に丸められる。
    inp = make_input(5, 0, 10, balls=[], baskets=[])
    ops = list("MFFFMPPP")
    assert len(ops) <= inp.T
    expanded = expand_output(inp, ops)
    assert len(expanded) == 10  # T で打ち切り


def test_wall_blocks_forward() -> None:
    # N=2、(0,0) と (0,1) の間に縦壁。F しても進めず留まる。
    wall_v = [[True], [False]]  # wall_v[0][0]=True
    wall_h = [[False, False]]
    inp = make_input(2, 0, 100, balls=[], baskets=[], wall_v=wall_v, wall_h=wall_h)
    ops = list("F")
    # M=0 なので score は完了扱い=len(ops)=1、エラーなし。
    score, err, v = compute_score(inp, ops)
    assert err == ""
    assert score == 1
    # 位置が動いていないことは simulate 経由で確認
    from scorer import Sim

    sim = Sim(inp, ops)
    sim.run_until(inp.T)
    assert sim.p == (0, 0)  # 壁で前進できず


def _run_all() -> None:
    fns = [g for name, g in sorted(globals().items()) if name.startswith("test_")]
    failed = 0
    for fn in fns:
        try:
            fn()
            print(f"PASS {fn.__name__}")
        except AssertionError as e:
            failed += 1
            print(f"FAIL {fn.__name__}: {e}")
        except Exception as e:  # noqa: BLE001
            failed += 1
            print(f"ERROR {fn.__name__}: {type(e).__name__}: {e}")
    print(f"\n{len(fns) - failed}/{len(fns)} passed")
    if failed:
        raise SystemExit(1)


if __name__ == "__main__":
    _run_all()
