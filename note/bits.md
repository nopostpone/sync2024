# 位运算 入门

本人完全没位运算基础，因此整理一些不难，但（赛时）做不出的位运算题目

## [CF1988C Increasing Sequence with Fixed OR](https://codeforces.com/contest/1988/problem/C)

给你一个正整数 $n$，需要构造最长的序列满足：

- 所有数都小于 $n$，
- 严格递增，
- 任意两个相邻的元素按位或运算的结果为 $n$。

解：
<details>

从“严格递增，尽可能长”角度想，构造形式如下的序列可满足题意。

```
1 1 1 1 1 <- 还可以塞一个 n 进去

1 1 1 1 0
1 1 1 0 1
1 1 0 1 1 
1 0 1 1 1
0 1 1 1 1
```

先得到 $n$ 的二进制，对于每一位 $1$ 就可以推一个除了这一位是 $0$，其余都与 $n$ 相同的二进制数进入答案。

由于还可以塞一个 $n$，因此数量就是 `size + 1`。

需要特判 $n$ 只有一位是 $1$ 的情况，这种情况下只有 $n$ 本身满足要求。

核心代码：

```cpp
void solve() {
    ll n;
    cin >> n;

    vector<ll> p;
    for (int i = 0; i <= 60; i++) {
        if (n & (1LL << i))
            p.push_back(1LL << i);
    }
    if (p.size() == 1) {
        cout << 1 << '\n' << p[0] << endl;
        return;
    }

    cout << p.size() + 1 << "\n";
    for (int i = p.size() - 1; ~i; i--) {
        ll sum = 0;
        for (auto x : p) {
            if (x != p[i]) {
                sum += x;
            }
        }
        cout << sum << ' ';
    }
    cout << n << "\n";
}
```

</details>

## [CF1994B Fun Game](https://codeforces.com/contest/1994/problem/B)

给出两个序列 $s$ 和 $t$，问能不能通过任意次操作把 $s$ 变成 $t$，操作内容如下：

选一组 $(l, r)$ 满足 $1 \leq l \leq r \leq n$，对于 $[l, r]$ 中的每一个元素 $s_i$，将其替换为 $s_i \oplus s_{i - l + 1}$。

解：
<details>

$1\oplus 1 = 0$， $0\oplus 1 = 1$。

核心代码：
```cpp
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size() && s[i] == '0'; i++) {
        if (t[i] != '0') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
```

</details>

## [abc365_e](https://atcoder.jp/contests/abc365/tasks/abc365_e)

给定长为 $N$ 的整数数组 $A=(A_1,\ldots,A_N)$，求：

$$\displaystyle \sum_{i=1}^{N-1}\sum_{j=i+1}^N (A_i \oplus A_{i+1}\oplus \ldots \oplus A_j)$$

-   $2 \leq N \leq 2 \times 10^5$
-   $1 \leq A_i \leq 10^8$

解：
<details>

以 $\text{pre}_i$ 表示 $i$ 的**异或前缀和**，那么有

$$A_l \oplus A_{l+1}\oplus \ldots \oplus A_r = \text{pre}_r \oplus \text{pre}_{l - 1}$$

则原式可化为

$$\displaystyle \begin{align*} \sum_{i=1}^{N-1}\sum_{j=i+1}^N (A_i \oplus A_{i+1}\oplus \ldots \oplus A_j) &= \sum_{i = 0}^{n - 2}\sum_{j = i + 2}^{n}(\text{pre}_i \oplus \text{pre}_j)\\ &= \sum_{0\leq i \leq n - 2 \atop i + 2 \leq j \leq n}(\text{pre}_i \oplus \text{pre}_j)\end{align*} $$

由于异或的特性，对于 $\text{pre}_i$ 中的每一个数位：

- 若为 $1$，则对答案的贡献为 $[i + 2, n]$ 中每个异或前缀和，在该数位上 $0$ 的个数。

- 若为 $0$，同理，为上述区间中 $1$ 的个数。

不妨再开一个数组 `s`，记录 `pre` 中每一数位的前缀和，易得答案，核心代码如下。

```cpp
ll res = 0;
for (int i = 0; i <= n - 2; i++) {
    for (int j = 0; j < 28; j++) {
        if (a[i] & (1 << j)) {
            // 统计 0 的个数：区间长度 - 1 的个数
            res += 1ll * (n - i - 1 - (s[n][j] - s[i + 1][j])) * (1 << j);
        } else {
            res += 1ll * (s[n][j] - s[i + 1][j]) * (1 << j);
        }
    }
}

cout << res << endl;
```

[完整代码](https://atcoder.jp/contests/abc365/submissions/56961585)

</details>