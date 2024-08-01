# 位运算 入门

整理不是很难，但做不出的位运算题目

## [CF1988C](https://codeforces.com/contest/1988/problem/C)

You are given a positive integer $n$. Find the **longest** sequence of positive integers $a=[a_1,a_2,\ldots,a_k]$ that satisfies the following conditions, and print the sequence:

-   $a_i\le n$ for all $1\le i\le k$.
-   $a$ is strictly increasing. That is, $a_i>a_{i-1}$ for all $2\le i\le k$.
-   $a_i\,|\,a_{i-1}=n$ for all $2\le i\le k$, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

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

先得到 $n$ 的二进制，对于每一位 $1$ 就可以推一个除了这一位是 $0$，其余都是 $1$ 的二进制数进入答案。

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