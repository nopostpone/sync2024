# 线段树

线段树是一种区间二叉搜索树，能维护和询问区间上的一些性质，采用分治的思想，复杂度 $O(\log{n})$，原理见 [oiwiki 的线段树部分](https://oiwiki.com/ds/seg/#%E7%BA%BF%E6%AE%B5%E6%A0%91)。

## 维护区间和

### a. 区间加

[**模板题：luogu P3372**](https://www.luogu.com.cn/problem/P3372)

最简单的模型，维护 `add` 标记即可。

<details>

线段树的大致模板见下。

```cpp
// https://www.luogu.com.cn/problem/P3372
#include <bits/stdc++.h>
// lst, rst 为位于 pos 的结点的左右子节点（用位运算快）
#define lst pos << 1 // lst = 2 * pos
#define rst pos << 1 | 1 // rst = 2 * pos + 1
const int N = 1e6 + 5;

int n, m;
std::vector<int> a;
std::vector<long long> res;

struct node {
    int l, r;
    long long add; // 懒标记
    long long sum; // 区间和
} s[N << 2]; // 开四倍 N 的空间

void pullup(int pos) {
    s[pos].sum = s[lst].sum + s[rst].sum;
}

void build(int l, int r, int pos) {
    s[pos] = {l, r, 0, 0}; // 初始化
    // 如果 l 与 r 相同，就说明该节点是叶子节点
    if (l == r) {
        s[pos].sum = a[l]; // 叶子节点的值就是数组中这个点的值
        return;
    }
    int mid = l + r >> 1;
    // 分别建左右子树
    build(l, mid, lst);
    build(mid + 1, r, rst);
    // 回收标记（向上更新）
    pullup(pos);
}

void pushdown(int pos) {
    // 更新左右子树区间和
    // sum = add * 区间长度
    s[lst].sum += s[pos].add * (s[lst].r - s[lst].l + 1);
    s[rst].sum += s[pos].add * (s[rst].r - s[rst].l + 1);
    // 下放标记
    s[lst].add += s[pos].add;
    s[rst].add += s[pos].add;
    // 原标记置 0
    s[pos].add = 0;
}

void upd(int x, int y, int k, int pos = 1) {
    if (x <= s[pos].l and s[pos].r <= y) {
        s[pos].sum += (s[pos].r - s[pos].l + 1) * k;
        s[pos].add += k;
        return;
    }
    // 如果有标记则下放
    if (s[pos].add) {
        pushdown(pos);
    }
    // 更新左右子树
    int mid = s[pos].l + s[pos].r >> 1;
    if (x <= mid) {
        upd(x, y, k, lst);
    }
    if (mid < y) {
        upd(x, y, k, rst);
    }
    // 标记回收
    pullup(pos);
}

long long query(int x, int y, int pos = 1) {
    // 询问原理同更新
    if (x <= s[pos].l and s[pos].r <= y) {
        return s[pos].sum;
    }
    pushdown(pos);
    int m = s[pos].l + s[pos].r >> 1;
    long long ans = 0;
    if (x <= m)
        ans += query(x, y, lst);
    if (m < y)
        ans += query(x, y, rst);
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    build(1, n, 1);
    for (int i = 1; i <= m; i++) {
        int opt, x, y, k;
        std::cin >> opt >> x >> y;
        if (opt == 1) {
            std::cin >> k;
            upd(x, y, k);
        } else {
            res.push_back(query(x, y));
        }
    }
    for (auto i: res) {
        std::cout << i << '\n';
    }

    return 0;
}
```

</details>

### b. 区间乘 + 加

[**模板题：luogu P3373**](https://www.luogu.com.cn/problem/P3373)

维护两个懒标记 `add, mul`，需要注意乘和加的顺序，以 `pushdown()` 函数为例：

```cpp
void pushdown(ll pos)
{
    if (s[pos].add == 0 and s[pos].mul == 1)
        return;
    s[lst].sum = (s[lst].sum * s[pos].mul + s[pos].add * (s[lst].r - s[lst].l + 1)) % P,
    s[rst].sum = (s[rst].sum * s[pos].mul + s[pos].add * (s[rst].r - s[rst].l + 1)) % P,
    s[lst].mul = (s[lst].mul * s[pos].mul) % P,
    s[rst].mul = (s[rst].mul * s[pos].mul) % P,
    s[lst].add = (s[lst].add * s[pos].mul + s[pos].add) % P,
    s[rst].add = (s[rst].add * s[pos].mul + s[pos].add) % P,
    s[pos].add = 0, s[pos].mul = 1;
}
```

[完整代码](/sol/luogu/P3373.cpp)

### c. 区间异或

[**模板题：CF242E**](https://www.luogu.com.cn/problem/CF242E)

拆位 + 线段树维护，在节点设置一个数组，记录区间每个数位上有多少个 $1$。

<details>

```cpp
struct node
{
    ll l, r, tag;
    vector<int> bit;
} s[N << 2];
```

建树时，对每个叶子节点，统计各数位上 $1$ 的分布，方法如下。

```cpp
void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r, s[pos].bit.resize(21);
    if (l == r)
    {
        for (int i = 20; ~i; i--)
        {
            if (a[l] & (1 << i))
            {
                s[pos].bit[i] = 1;
            }
        }
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pullup(pos);
}
```

异或时区间上取反（以 `pushdown()` 函数为例）

```cpp
void pushdown(ll pos)
{
    if (s[pos].tag)
    {
        s[lst].tag ^= s[pos].tag;
        s[rst].tag ^= s[pos].tag;
        for (int i = 20; ~i; i--)
        {
            if (s[pos].tag & (1 << i))
            {
                s[lst].bit[i] = s[lst].r - s[lst].l + 1 - s[lst].bit[i];
                s[rst].bit[i] = s[rst].r - s[rst].l + 1 - s[rst].bit[i];
            }
        }
        s[pos].tag = 0;
    }
}
```

这样每个区间的 `bit[]` 就维护了每个数位上有多少个 $1$，询问时把二进制转化成十进制即可。

```cpp
ll query(ll x, ll y, ll pos = 1)
{
    ll ans = 0;
    if (x <= s[pos].l and s[pos].r <= y)
    {
        for (int i = 20; ~i; i--)
        {
            ans += 1LL * (1 << i) * s[pos].bit[i];
        }
        return ans;
    }
    pushdown(pos);
    ll m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        ans += query(x, y, lst);
    if (m < y)
        ans += query(x, y, rst);
    return ans;
}
```

[完整代码](/sol/CF/242E.cpp)

</details>

### d. 区间开方

[**例题：luogu P4145**](https://www.luogu.com.cn/problem/P4145)

仅需维护区间最大值，当区间最大值为 1，那么开方就无意义了，若不为 1，则继续暴力遍历直到叶子节点。

<details>

以更新函数 `upd()` 为例。

```cpp
void upd(int x, int y, int pos = 1) {
    if (s[pos].mx == 1) {
        return;
    }
    if (s[pos].l == s[pos].r) {
        s[pos].mx = s[pos].sum = sqrt(s[pos].sum);
        return;
    }
    int m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        upd(x, y, lst);
    if (m < y)
        upd(x, y, rst);
    pullup(pos);
    return;
}
```

[完整代码](/sol/luogu/P4145.cpp)

</details>

## 维护最大连续区间

维护最大连续区间，需要在每个节点维护前缀最大连续，后缀最大连续和最大连续三个信息。

以 `pullup` 为例。

```cpp
void pullup(int pos) {
    // 前缀 = 左子树前缀
    s[pos].ls = s[lst].ls;
    // 后缀 = 右子树后缀
    s[pos].rs = s[rst].rs;
    // 如果左子树前缀 = 左区间长度，那么说明左子树全是连续的，要再算上右子树的前缀
    if (s[lst].ls == s[lst].r - s[lst].l + 1) {
        s[pos].ls += s[rst].ls;
    }
    // 右子树后缀同理
    if (s[rst].rs == s[rst].r - s[rst].l + 1) {
        s[pos].rs += s[lst].rs;
    }
    // 最长连续 = max{前缀，后缀，左子树最长区间，右子树最长区间，左后缀与右前缀之和}
    s[pos].sum = max({s[pos].ls,
                      s[pos].rs,
                      s[lst].sum,
                      s[rst].sum,
                      s[lst].rs + s[rst].ls});
}
```

要重点关注询问的思路。

对于 $[x, y]$ 区间找最大连续段，要讨论跨区间连续的情况，下面举个例子。

有一颗在 $[1, 5]$ 上的线段树，该区间每个位置上都是 $0$。

现在要统计 $[3, 4]$ 上最大连续区间。

如果按照常规的求区间最大值的办法：先从管辖 $[1, 5]$ 的节点开始，逐渐遍历到 $[3, 3]$ 和 $[4, 4]$，然后得到答案 $1$，那么显然是不对的，因为答案是 $2$， $[3, 3]$ 和 $[4, 4]$ 的 $0$ 是跨区间连续的。

要怎么解决这个问题呢，其实也不难，在从子区间得到值之后，额外讨论一下跨区间连续的情况（即左子树的后缀 + 右子树的前缀）即可，代码如下。

```cpp
int querymx(int x, int y, int pos = 1) {
    if (x <= s[pos].l and s[pos].r <= y) {
        return s[pos].ss[1];
    }
    pushdown(pos);
    int mid = s[pos].l + s[pos].r >> 1;
    int tmp = 0;
    if (x <= mid)
        tmp = max(tmp, querymx(x, y, lst));
    if (mid < y)
        tmp = max(tmp, querymx(x, y, rst));

    int tmpr = min(s[lst].rs[1], mid - x + 1), tmpl = min(s[rst].ls[1], y - mid);
    tmp = max(tmp, tmpr + tmpl);
    return tmp;
}
```

[**例题：luogu P6492**](https://www.luogu.com.cn/problem/P6492)

求 $LR$ 相间的最长连续区间，其实可以转换成求最长 $L$ 或 $R$ 区间，仅需在最开始把奇数位置的 $L$ 翻转即可。

<details>

预处理：设 $L$ 为 $0$，设 $R$ 为 $1$。

```cpp
for (int i = 1; i <= n; i += 2)
{
    a[i] = 1;
}
```

在线段树中同时维护 $0$ 和 $1$ 的连续信息即可，建树操作见下。

```cpp
struct node {
    int l, r, ls[2], sum[2], rs[2];
} s[N * 4];

void pullup(int pos) {
    for (int i : {0, 1}) {
        s[pos].ls[i] = s[lst].ls[i];
        s[pos].rs[i] = s[rst].rs[i];
        if (s[lst].ls[i] == s[lst].r - s[lst].l + 1) {
            s[pos].ls[i] += s[rst].ls[i];
        }
        if (s[rst].rs[i] == s[rst].r - s[rst].l + 1) {
            s[pos].rs[i] += s[lst].rs[i];
        }
        s[pos].sum[i] = max({s[pos].ls[i],
                             s[pos].rs[i],
                             s[lst].sum[i],
                             s[rst].sum[i],
                             s[lst].rs[i] + s[rst].ls[i]});
    }
}

void build(int l, int r, int pos) {
    s[pos] = {l, r, {0, 0}, {0, 0}, {0, 0}};
    if (l == r) {
        int i = a[l];
        s[pos].ls[i] = s[pos].rs[i] = s[pos].sum[i] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pullup(pos);
}
```

翻转操作如下。

```cpp
void upd(int x, int pos = 1)
{
    // 暴力到每个叶子节点
    if (s[pos].l == s[pos].r)
    {
        // 翻转
        s[pos].rs ^= 1;
        s[pos].ls ^= 1;
        s[pos].sum ^= 1;
        return;
    }
    int m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        upd(x, lst);
    else
        upd(x, rst);
    pullup(pos);
    return;
}
```

询问时同时找 $0$ 和 $1$ 的最大连续区间，输出两者的较大值。

[完整代码](/sol/luogu/P6492.cpp)

</details>
<br>

[**难但典型的例题：luogu P2572**](https://www.luogu.com.cn/problem/P2572)

这题需要实现区间赋值和区间翻转，在更新中要维护“$1$ 的个数（即区间和）”和“最大连续 $1$ 区间”。

上一题只有翻转，而且是点修，在更改的过程中肯定是递归到最深层再拉上来的，所以无需下放操作。

但对于此题的区间操作，就需要标记下放了。

<details>
考虑在线段树每个节点维护 $9$ 个信息：

- 是否有赋值
- 是否有翻转
- $0$ 的前缀连续个数
- $1$ 的前缀连续个数
- $0$ 的后缀连续个数
- $1$ 的后缀连续个数
- $0$ 的最多连续个数
- $1$ 的最多连续个数
- 区间和

```cpp
struct node {
    int l, r;
    // ss：最多连续个数
    // ls：前缀连续个数
    // rs：后缀连续个数
    // sum：1 的个数
    int ss[2], ls[2], rs[2], sum;
    // tag 表示是否有赋值：-1表示没有赋值，0和1分别表示区间赋值0和1
    int tag, rev;
} s[N << 2];
```

上拉同上题，道理一样，重点看看下放。

因为在更新和下放时，都涉及到对单个区间的操作，我们不妨单独设置一个由给定的标记改变当前区间的函数，如下所示。

```cpp
// o 为标记：o = 2 代表翻转，o = 0 或 o = 1 代表区间赋 0 或 1
void modify(int pos, int o) {
    if (o == 0 or o == 1) {
        // 赋值的优先级大于翻转，一旦赋值，翻转标记就置 0
        s[pos].tag = o;
        s[pos].rev = 0;
        s[pos].sum = (s[pos].r - s[pos].l + 1) * o;
        s[pos].ls[o] = s[pos].rs[o] = s[pos].ss[o] = s[pos].r - s[pos].l + 1;
        s[pos].ls[o ^ 1] = s[pos].rs[o ^ 1] = s[pos].ss[o ^ 1] = 0;
    } else {
        // 如果 o 不是 0 或 1，那么就是 2，进行区间翻转

        // 如果该区间本来就有赋值标记，则翻转赋值标记
        if (~s[pos].tag) {
            s[pos].tag ^= 1;
        // 否则翻转 翻转标记
        } else {
            s[pos].rev ^= 1;
        }
        s[pos].sum = s[pos].r - s[pos].l + 1 - s[pos].sum;
        swap(s[pos].ls[0], s[pos].ls[1]);
        swap(s[pos].rs[0], s[pos].rs[1]);
        swap(s[pos].ss[0], s[pos].ss[1]);
    }
}
```

那么 `pushdown` 就可以简化写法，如下。

```cpp
void pushdown(int pos) {
    if (~s[pos].tag) {
        modify(lst, s[pos].tag);
        modify(rst, s[pos].tag);
        s[pos].rev = 0;
        s[pos].tag = -1;
    }
    if (s[pos].rev) {
        modify(lst, 2);
        modify(rst, 2);
        s[pos].rev = 0;
    }
}
```

其他和上题大同小异。

[完整代码](/sol/luogu/P2572.cpp)

</details>

## 权值线段树 - 查找前驱后继

## 势能线段树（吉司机线段树）

[**例题：CF765F**](https://www.luogu.com.cn/problem/CF765F)

题意：给出一个长为 $n$ 的序列 $a$，和 $m$ 组询问。 每个询问给出一组 $(l, r)$，对 $\forall i,j \in [l,r]$，且满足 $i\neq j$，求 $|a_i - a_j|$ 的最小值。
