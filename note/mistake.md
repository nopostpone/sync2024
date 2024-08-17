# 记录一些铸币时刻

[abc362_c](https://atcoder.jp/contests/abc362/tasks/abc362_c)

You are given $N$ pairs of integers $(L_1, R_1), (L_2, R_2), \ldots, (L_N, R_N)$.

Determine whether there exists a sequence of $N$ integers $X = (X_1, X_2, \ldots, X_N)$ that satisfies the following conditions, and print one such sequence if it exists.

-   $L_i \leq X_i \leq R_i$ for each $i = 1, 2, \ldots, N$.
-   $\displaystyle \sum_{i=1}^N X_i = 0$.

[WA](https://atcoder.jp/contests/abc362/submissions/56771429) ：漏了 sum 加完之后仍为负的情况

[AC](https://atcoder.jp/contests/abc362/submissions/56771626)