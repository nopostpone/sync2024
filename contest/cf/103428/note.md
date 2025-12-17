## [The 2021 CCPC Weihai Onsite](https://codeforces.com/gym/103428)


### M

题意：大小为 $n$ 的 `01` 串，求：有 $m$ 个 `1`，且最长 `1` 连续段长度恰好为 $k$ 的方案数。

思路：

设 $f(x)$ 为：有 $m$ 个 `1`，且最长 `1` 连续段长度**不大于**为 $k$ 的方案数。则答案为 $f(x) - f(x - 1)$。下面来看怎么求 $f(x)$。

设全集为 $U$，有 $|U|= \dbinom{n}{m}$。我们想象什么时候是不行的，显然是存在一个长度不小于 $x+1$ 的段，我们称之为坏段。如果字符串中先把 `0` 的位置都放好，那么这个坏段肯定会出现在某个间隙中。

设坏事件 $A_j$ 为第 $j$ 个间隙中出现坏段，则

$$
\begin{align*}
f(x)&=|\overline{A_1 \cup A_2\cup \cdots\cup A_{n-m+1}}|\\
&= |U| -\sum_{j}|A_j|+\sum_{j<l}|A_j \cap A_l|-\dots+(-1)^{n-m+1}|A_1 \cap A_2\cap \cdots\cap A_{n-m+1}|
\end{align*}
$$

对于有 $i$ 个坏段，先把坏段的位置固定下来，即在 $(n-m+1)$ 个间隙中插入 $i$ 个坏段，有 $\dbinom{n-m+1}{i}$ 个方案。

接着，就是坏段之外的 `1` 放哪里了。剩下 $m-(k+1)i$ 个 `1`，分成 $(n-m+1)$ 组，每组允许为空，这是一个经典的[插板法模型](https://oi-wiki.org/math/combinatorics/combination/#%E9%9D%9E%E8%B4%9F%E6%95%B4%E6%95%B0%E5%92%8C%E7%9A%84%E6%95%B0%E7%9B%AE)，其方案数为 $\dbinom {m-(k+1)i+n-m+1-1}{n-m+1-1}=\dbinom{n-(k+1)i}{n-m}$。

两个乘起来再乘前面的容斥系数就行了。这道题的模型非常经典。

代码：

```cpp
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    if (n < m or m < k) {
        cout << 0 << "\n";
        return 0;
    }

    auto f = [&](int k) -> Z {
        if (k < 0) {
            return 0;
        }
        if (m == 0) {
            return 1;
        }
        Z res = 0;
        for (int i = 0; i <= n - m + 1 && i * (k + 1) <= m; i++) {
            res += (i & 1 ? -1 : 1) *
                   comb.binom(n - m + 1, i) *
                   comb.binom(n - i * (k + 1), n - m);
        }
        return res;
    };

    auto ans = f(k) - f(k - 1);
    cout << ans << "\n";

    return 0;
}
```

### E

题意：任选两个数求和，可以重选 $k$ 次的期望。然后回答 $q$ 个子询问，问你选择位置 $x$ 和 $y$，且还有 $c$ 次重选机会时，最优策略是什么（接受、重选或者都可以）。

思路：

设 $E_i$ 为还有 $i$ 次重选机会时的期望，则有

$$
E_{i+1}=\frac 1{\dbinom n2}\sum_{1\leq l < r\leq n}\max\{a_l+a_r, E_i\}
$$

意思就是随机选了两个数，如果这两个数的和比上一次期望大，那就不重选，否则就重选，而重选的结果就是上一次重选的期望。

回答询问就很简单了，把 $a_x+a_y$ 与 $E_{c-1}$ 比较即可。

实现上，可以用双指针或者二分来优化 $l$ 和 $r$ 的选取。前者复杂度为 $O(n\log n+nk+q)$，后者为 $O(nk \log n+q)$。$nk=10^7$，再带个 $\log$ 有点危险，但还是能过去的。

代码：

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto oa = a;

    ranges::sort(a);
    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<double> dp(k + 1);
    const double C = (double)n * (n - 1) / 2;

    dp[0] = (double)pre[n] * (n - 1) / C;

    for (int i = 0; i < k; i++) {
        i64 sum = 0;
        i64 cnt = 0;

        int l = 0, r = n;
        while (l + 1 < r) {
            while (l + 1 < r and a[l] + a[r - 1] > dp[i]) {
                r--;
            }
            if (l + 1 >= r) {
                break;
            }
            cnt += r - (l + 1);
            sum += pre[n] - pre[r] + (i64)(n - r) * a[l];
            l++;
        }
        sum += (pre[n] - pre[l]) * (n - l - 1);
        dp[i + 1] = (dp[i] * cnt + sum) / C;
    }

    cout << fixed << setprecision(15) << dp[k] << "\n";

    constexpr double e = 1e-4;

    for (int i = 0; i < q; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;

        if (c == 0) {
            cout << "accept\n";
            continue;
        }
        double cur = oa[x] + oa[y];
        double opt = dp[c - 1];

        if (abs(cur - opt) <= e) {
            cout << "both\n";
        } else if (cur > opt) {
            cout << "accept\n";
        } else {
            cout << "reselect\n";
        }
    }

    return 0;
}
```
### F

题意：$n$ 堆石子，两个人轮流取，第一个人可以选择一个数 $s_1$，然后从任意堆石子里取 $s_1$ 个。后面每个人选择的数 $s_i$ 都要是前一个人选择的 $s_{i-1}$ 的因子。问先手有几种获胜策略。

思路：

代码：

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ok = false;
    do {
        for (auto x : a) {
            if (x & 1) {
                ok = true;
            }
        }
        if (not ok) {
            for (auto &x : a) {
                x /= 2;
            }
        }
    } while (not ok);

    int ans = INT_MAX;
    for (auto x : a) {
        if (x & 1) {
            ans = min(ans, x);
        }
    }
    cout << (ans + 1) / 2 << "\n";

    return 0;
}
```