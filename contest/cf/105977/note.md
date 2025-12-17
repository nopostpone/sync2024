## [2025 FJCPC](https://codeforces.com/gym/105977)

### B

假设奖牌数量加起来为 $n$，枚举金牌的数量 $g$ 和银牌的数量 $s$，先不合成铜牌，则铁牌数量 $fe = n - 8g - 4s$。我们要价值加起来大于等于 $p$，就是要 $4g + 3s + fe\geq p$。

因为铁牌合成铜牌，总价值是不变的，因此我们可以尽可能多地把铁牌合成铜牌。即在 $4g + 3s + fe\geq p$ 的情况下，对于 $i\in[g+s+\lceil\dfrac{fe} 2\rceil, \ g + s + fe]$，方案数 $ans_i$ 增加 $1$。

现在就有一个 $O(n^2)$ 的算法，枚举 $g$ 和 $s$，答案统计用差分即可。

现在尝试优化掉一个维度，只枚举 $g$，那么 $s$ 有两个限制：

$$
\begin{cases}
8g+4s\leq n \\
4g+3s+(n-8g-4s)\geq p
\end{cases}
$$

即 $s \leq \min(n-4g-p,\ \lfloor\dfrac{n-8g}{4}\rfloor)$。

再看 $[g+s+\lceil\dfrac{fe} 2\rceil, \ g + s + fe]$，把 $fe$ 代入，化简为 $[\lceil \dfrac n2\rceil -3g-s, \ n-7g-3s]$。我们发现，对于 $s$ 取 $0, 1, 2\cdots$，区间左端点是一个公差为 $1$ 的等差数列，右端点则是公差为 $3$ 的等差数列。

那 $O(n)$ 的做法就出来了，枚举 $g$，算得 $s$ 的上界，然后维护两个二阶差分即可。

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> op1(n + 30), op3(n + 30);
    for (int g = 0; g <= n / 8; g++) {
        int r = min(n - 4 * g - p, (n - 8 * g) / 4);
        if (r < 0) {
            continue;
        }
        op1[(n + 1) / 2 - 3 * g - r]++;
        op1[(n + 1) / 2 - 3 * g + 1]--;
        
        op3[n - 7 * g - 3 * r + 1]--;
        op3[n - 7 * g + 4]++;
    }

    for (int i = 1; i <= n; i++) {
        op1[i] += op1[i - 1];
    }
    for (int i = 3; i <= n; i++) {
        op3[i] += op3[i - 3];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += op1[i] + op3[i];
        cout << ans << " \n"[i == n];
    }

    return 0;
}
```

### C

三个数合并成中位数，有一个非常经典的题：[agc006_d](https://www.luogu.com.cn/problem/AT_agc006_d)。

二分答案，对于答案 $x$，令小于 $x$ 的 $a_i$ 为 $0$，其余为 $1$，那么我们就要尽可能让最后留下来的数字为 $1$。

先看 `0101010` 这种 `01` 交错的情况，可以发现，哪个数字多，最后就留下的是哪个数字，又因为 $n$ 是奇数，所以不会出现 `0` 和 `1` 数量相等。

如果有两个连续的 `0` 呢？比如 `001001011`，我们可以把前三个先合并，变成 `0001011`，再合并前三个，变成 `01011`，结果就是 `1`。

可以发现，遇到两个连续的 `0`，可以立即把它们和任意相邻的数字合并，这样总是不会劣的。于是我们维护一个类似栈的结构，在遍历时，当顶和顶下面的元素都是 `0`，我们就 `pop` 两次，再推一个 `0` 进去；否则把当前数字推进去。最后再比较两个数字的数量即可。复杂度 $O(n\log V)$。

```cpp
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int x) {
        vector<int> na(n);
        for (int i = 0; i < n; i++) {
            na[i] = a[i] >= x;
        }

        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (int t = stk.size(); t >= 2 and stk[t - 1] == 0 and stk[t - 2] == 0) {
                stk.pop_back();
                stk.pop_back();
                stk.push_back(0);
            } else {
                stk.push_back(na[i]);
            }
        }

        int c1 = count(stk.begin(), stk.end(), 1);
        int c0 = (int)stk.size() - c1;

        return c1 > c0;
    };

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    cout << lo << "\n";
}
```

### E

首先最差情况时，拿的牌之和肯定不比对手的大，否则交换你和对手的牌，就有更差的情况了。

假设最差情况下你的牌和为 $a$，对手牌和为 $b$，$s=a+b$，$d=b-a$，那么 $a=\frac{s-d}{2}$，因此求出最小的差 $d$，就能得出最大的 $a$。

现在来看怎么通过交换让 $d$ 最小。

把一张牌拿出来插到另一张牌下面，本质上就是选一个长度为偶数的区间，让区间中的**奇偶的和**互换。比如 `1` 换到 `4` 下面，就变成 `2 3 4 1`，原来偶位置是 `2 4`，现在变成了 `3 1`，虽然顺序变了，但是和是不变的。

由此，设

$$
A_i=\sum_{1\leq 2i+1\leq n} a_i，B_i=\sum_{1\leq 2i \leq n} a_i
$$

选择长度为偶数的区间 $[l, r]$，带来的差值是

$$
\Delta=|A_n-B_n-2(A_r-A_{l-1})+2(B_r -B_{l-1})|
$$

设 $d_i=A_i-B_i$，有

$$
\Delta=|d_n-2d_r+2d_{l-1}|
$$

从前到后扫过去，用 `std::set` 维护让 $\Delta$ 接近 $0$ 的 $l$ 即可。

```cpp
void solve() {
    int n;
    cin >> n;

    n *= 2;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<i64> pre[2]{};
    pre[0].assign(n + 1, 0);
    pre[1].assign(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        pre[i & 1][i + 1] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[0][i] += pre[0][i - 1];
        pre[1][i] += pre[1][i - 1];
    }

    vector<i64> d(n + 1);
    for (int i = 0; i <= n; i++) {
        d[i] = pre[0][i] - pre[1][i];
    }

    i64 ans = 1e18;
    set<i64> s[2] {};
    s[0].insert(d[0]);
    for (int r = 1; r <= n; r++) {
        int j = r & 1;

        auto it = s[j].lower_bound(-(d[n] - 2 * d[r]) / 2);
        if (it != s[j].end()) {
            ans = min(ans, abs(d[n] - d[r] * 2 + *it * 2));
        }
        if (it != s[j].begin()) {
            it = prev(it);
            ans = min(ans, abs(d[n] - d[r] * 2 + *it * 2));
        }
        s[j].insert(d[r]);
    }
    
    cout << (pre[0][n] + pre[1][n] - ans) / 2 << "\n";
}
```

### H

一步能走 $x$ 格，那么前进的范围是 $x, x-2, x-4, \cdots$，也就是说，前进的格数奇偶性是不变的。

用 bfs 求出奇偶数的最短路。后对 $l$，$r$ 作一些分类讨论即可。

具体地，分为 $l=r$，与 $l\neq r$。

- $l=r$

    - $r$ 为偶数，则只能走偶数最短路，若偶数最短路不存在，那么就无解。

    - $r$ 为奇数，奇偶最短路都能走。但需要注意的是，奇数步，奇偶性会随步数变化。设 $d_i,\ i\in[0,1]$ 为奇偶数最短距离，$t_i = \lceil \frac{d_i}r \rceil$，答案为 $t_i + [t_i \neq d_i \mod 2]$，即若 $t_i$ 与 $d_i$ 的奇偶性不同，需要再花一步来调整。

- $l\neq r$ 那就什么都能走了，不再赘述。

复杂度 $O(Dnm)$，其中 $D=8\times8=64$。以下代码为 bfs 计算最短路的部分。

```cpp
void solve() {
    /**
     * ...
     */

    auto bfs = [&](const vector<pair<int, int>> &st, int t) {
        queue<pair<int, int>> q;

        vector f(n, vector<int>(m, inf));
        for (auto [x, y] : st) {
            q.emplace(x, y);
            f[x][y] = t;
        }

        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (not valid(x1, y1)) {
                    continue;
                }

                for (int j = 0; j < 8; j++) {
                    int x2 = x1 + dx[j];
                    int y2 = y1 + dy[j];
                    if (not valid(x2, y2)) {
                        continue;
                    }
                    if (f[x2][y2] == inf) {
                        f[x2][y2] = f[x][y] + 2;
                        q.emplace(x2, y2);
                    }
                }
            }
        }

        return f[n - 1][m - 1];
    };

    int d[2] {};
    d[0] = bfs({{}}, 0);

    vector<pair<int, int>> nxt;
    for (int i = 0; i < 8; i++) {
        int x = dx[i];
        int y = dy[i];

        if (valid(x, y)) {
            nxt.emplace_back(x, y);
        }
    }

    d[1] = bfs(nxt, 1);
    /**
     * ...
     */
}
```

### I

就是把一个环放到一个链上，环上所有点都是割点，链上所有点都是非割点。

### J

不断令 $n:=n+\text{lowbit}(n)$ 即可，因为 $2^{2i}$ 一定是完全平方数。

### K

设根为 $x$，dfs 整颗树，得到每个点与 $x$ 的关系。由于每个点的权值都是正整数，再扫一遍所有点，来维护 $x$ 的范围 $[l, r]$。当 $r<l$，无解。

### L

todo