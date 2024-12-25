## A

如果取 $a_i$，就要取 $b_{i + 1}$，要最大化 $\text{sum}_a - \text{sum}_b$，那么当 $a_i > b_{i + 1}$，就可以取这俩，需要注意边界。

## B

先除以三个的和，取整数部分，然后对模分类讨论即可。

## C

如果 $k = n$，即所有题都知道，那每一套题都能过；

如果 $k < n - 1$，因为每套题都有 $n - 1$ 道，每一套题都过不了；

剩下 $k = n - 1$ 的情况，只需要检查会的题目中是否有不考的题，如果有，那就过不了这套题。

实现方面，用桶数组或 $\texttt {std::set}$ 即可。

## D

将题目的条件转化一下：

$$
x \leq \text{sum} - a_i - a_j \leq y \\
\text{sum} - a_i - y \leq a_j \leq \text{sum} - a_i - x
$$

那么可以二分对每个元素统计其贡献。我的方法是：对每个元素，先判断和它自己是不是满足条件，然后二分查找上界和下界，最后将统计的和减半就是答案。

代码见 [链接](https://codeforces.com/contest/2051/submission/297964726)。

## E

挺好的关于线段的维护问题。

将每个人的 $[a_i, b_i]$ 看作一条线段。考虑以一种方式遍历这些线段：当新加进来一条线段，表示买但是给差评的人多了一个；退出一条线段，则表示买的人和给差评的人都减少了一个，因为不买的人也不会给差评。对于每次加入或退出线段，都更新一次答案。

一种做法是：给每个端点打上标记，分辨是不是起点。将端点从小到大排序之后遍历。设 $c$ 为买的人数，$x$ 为买且给差评的人数。初始时价格最低，所有人都会买而且不会给差评，当遍历到起点，有 $x\leftarrow x+1$；遍历到终点则有 $c\leftarrow c-1$ 和 $x\leftarrow x - 1$。每遍历一个新的值时，若 $x \leq k$，更新一次答案。

代码见 [链接](https://codeforces.com/contest/2051/submission/297959039)。

## F

简单分类讨论一下可以发现：当操作 Joker 前面的牌，Joker 的位置可能会往前移动一格；操作后面的牌，可能往后移动一格；正好操作到 Joker 的位置，则会出现在最前或者最后。也就是说，Joker 可能出现的位置能组成三个区间：最前面的一段、最后面的一段，以及由初始位置 $m$ 扩展得到。

区间的扩展就如上所述，需要注意的是，当区间只有一张牌，且正好操作这个牌，那么该区间转移变成最前面或最后面。每次操作的答案就是三个区间的并。

思路比较好理解，但实现上略复杂，可能会漏一些情况。我参考了题解的写法：把区间放在数组里；每次先更新，再遍历统计答案。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    m--;
    
    // [l, r)
    vector<pair<int, int>> segs(3);
    segs[1] = {m, m + 1};
    segs[0] = {0, 0};
    segs[2] = {n, n};
    
    while (q--) {
        int x;
        cin >> x;
        x--;

        bool inside{};
        
        for (auto &&[l, r] : segs) {
            if (r - l < 1) {
                continue;
            }
            if (x < l) {
                l--;
                l = max(l, 0);
            } else if (x >= r) {
                r++;
                r = min(r, n);
            } else {
                inside = true;
                if (r - l == 1) {
                    r = l;
                }
            }
        }
        if (inside) {
            segs[0] = {0, max(segs[0].second, 1)};
            segs[2] = {min(segs[2].first, n - 1), n};
        }
        
        int ans{}, pos{};
        for (auto [l, r] : segs) {
            if (r - l < 1) {
                continue;
            }
            ans += r - max(l, pos);
            pos = r;
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}
```

## G

蛇伸展和收缩的时候，分别对应 $r$ 和 $l$ 的增加，可以发现，无论它怎么动，它“占领”的区间只会往前扩展，不会往后扩展。

题目要求的是，蛇和蛇之间不能撞的情况下，蛇所走到的最远的地方的最小值，好像有点复杂，我们分开来看。

首先，蛇和蛇不能相撞，那么任意两条蛇（有序对）初始的距离是可以确定的。由于 $n$ 很小，可以 $O(n^2q)$ 求出来——模拟所有操作，每次判断是不是撞到了，如果撞到了，两条蛇的距离就增加。

现在我们求出来了：在某一条蛇后布置另一条蛇，需要间隔的最近距离。那么以什么方式布置，可以使结果最小呢？我的方法是：跑一个哈密顿路，遍历每个点作为终点的结果，找出最小值。

代码如下，复杂度为 $O\left(n^2(q + 2^n)\right)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;

    vector<pair<int, char>> opt(q);
    for (int i = 0; i < q; i++) {
        cin >> opt[i].first >> opt[i].second;
        opt[i].first--;
    }

    // dis[i][j]：左蛇 i 和右蛇 j 的最小距离
    vector dis(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            // 左蛇的右端点，右蛇的左端点
            int ri{}, lj{1};
            for (auto [id, mov] : opt) {
                if (id == i) {
                    ri += (mov == '+');
                }
                if (id == j) {
                    lj += (mov == '-');
                }
                // 如果撞了，距离就增加 1
                if (ri == lj) {
                    ri--;
                    dis[i][j]++;
                }
            }
        }
    }

    // 哈密顿路
    // dp[i]：以 i 为终点，经过所有点的最短路。
    vector dp(n, vector<int>(1 << n, inf));
    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 1;
    }
    for (int s = 0; s < (1 << n); s++) {
        for (int d = 0; d < n; d++) {
            if (dp[d][s] == inf) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if ((s >> i) & 1) {
                    continue;
                }
                dp[i][s | (1 << i)] = min(dp[i][s | (1 << i)], dp[d][s] + dis[d][i]);
            }
        }
    }

    // 统计每个点作为终点的结果，找最小值
    int ans{inf};
    for (int i = 0; i < n; i++) {
        int x = dp[i].back();
        for (auto [id, mov] : opt) {
            if (id == i and mov == '+') {
                x++;
            }
        }
        ans = min(ans, x);
    }

    cout << ans << endl;
    
    return 0;
}
```