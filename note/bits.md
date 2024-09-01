# 位运算 入门

整理一些不难，但（赛时）做不出的位运算题目

## [CF1988C](https://codeforces.com/contest/1988/problem/C)

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

## [CF1994B](https://codeforces.com/contest/1994/problem/B)

给出两个序列 $s$ 和 $t$，问能不能通过任意次操作把 $s$ 变成 $t$，操作内容如下：

选一组 $(l, r)$ 满足 $1 \leq l \leq r \leq n$，对于 $[l, r]$ 中的每一个元素 $s_i$，将其替换为 $s_i \oplus s_{i - l + 1}$。

解：
<details>

观察一下异或的性质，不同的数异或之后为 1，相同的数异或为 0，打表观察一下：

$1\oplus 1 = 0$，$0\oplus 1 = 1$，

$0\oplus 0 = 0$，$1\oplus 0 = 1$。

可以发现，与 1 进行异或，就相当于取反；与 0 进行异或，就相当于不变，这个性质相当重要。

那么对于这道题，题意的意思是，每次操作可以任取区间 $[l, r]$，将这个区间里的元素与 $[1, r - l]$ 里一一对应的元素做异或，更直接地说，对每个数位，可以与它自身或者它之前的任意数位进行异或。

如果 $s$ 和 $t$ 在某一位置不同，要把 $s$ 变成 $t$，这个位置就必须取反，即要和 $1$ 异或。

因此，若 $t$ 出现第一个 $1$，但 $s$ 在这个位置以及之前全是 $0$，则 $s$ 不可能变为 $t$，否则 $s$ 一定能变成 $t$。

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

## [牛客小白月赛98 E](https://ac.nowcoder.com/acm/contest/85598/E)

给定一个长度为 $n$ 的序列 $a$，求出有多少个区间 $[l,r]$ 满足

$$ {2^{k_1}\leq (a_l\ \&\ a_{l+1}\ \&...\&\ a_r)\oplus(a_l\ |\ a_{l+1}\ |...|\ a_r)< 2^{k_2}}$$

- $n\ (1\leq n\leq 5\times 10^5)$

解：

<details>

把这个式子拆开看，左边是和运算，对任意一位，全 1 出 1，有 0 出 0；右边是或运算，全 0 出 0，有 1 出 1。

中间是个异或，对任意一位，两边若不同则出 1，也就是说，如果要这个数位最后结果是 1，对于我们选的区间，既要有 1 又要有 0，即 1 的个数 $\text{num}_{1, l, r} \in (0, r - l + 1)$。

题目要我们求的是，在 k1 和 k2 之间（左闭右开），存在至少一个位置满足要求，且大于等于 k2 的数位都不满足要求，这样的区间个数，我们可以转换成 $\text{res}_{0, k_2} - \text{res}_{0, k1}$，这么做方便许多。

核心代码如下。

```cpp
auto work = [&](int x) {
    ll ans = 0, cnt = 1;
    for (int i = 1; i < n; i++) {
        bool ok = true;
        for (int j = x; j < 64; j++) {
            bool u = a[i] >> j & 1;
            bool v = a[i - 1] >> j & 1;
            if (u != v) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cnt++;
        } else {
            ans += cnt * (cnt + 1) / 2;
            cnt = 1;
        }
    }
    ans += cnt * (cnt + 1) / 2;
    return ans;
};

cout << work(k2) - work(k1) << endl;
```

</details>

## [牛客小白月赛87 E](https://ac.nowcoder.com/acm/contest/73854/F)

给出一个长度为 $n$ 的数组 $a$，将数组 $a$ 分为**恰好非空的三段**。  

$\bullet$  第一段的所有数字做  $\oplus$（按位**异或**）运算。 

$\bullet$  第二段的所有数字做  $|$ （按位**或**）运算。  

$\bullet$  第三段的所有数字做  $\&$（按位**与**）运算。

将这三段数字运算的结果**加法求和**得到得分，求最大的得分。

解：
<details>

碰到切成三段的，一般都可以想一想固定其中一个切点的情况下，能不能 $O(\log n)$ 或 $O(1)$ 求出最优解，这样整体的复杂度就是 $O(n)$ 或 $O(\log n)$。

对于这题，第一段异或，第二段或，第三段与，最后相加。假如我们固定左边的切点，观察第二段和第三段，可以发现，第二段（或运算）长一点，值一定不会变小；第三段（与运算）长一点，值一定不会变大。因此最优解为 $A_3 = \{a_n\}$，即右切点在最后。

对第一段或者第二段的值做预处理（也可不做预处理），枚举左切点 $l$ 即可，核心代码如下。

```cpp
vector<int> prexor(n);
for (int i = 0; i < n - 1; i++) {
    prexor[i + 1] = prexor[i] ^ a[i];
}

ll res = -4e18; 
int x = 0;    
for (int i = n - 1; i > 1; i--) {
    x |= a[i - 1];
    res = max<ll>(res, 1ll * prexor[i - 1] + x);
}
cout << res + a[n - 1];
```

</details>
