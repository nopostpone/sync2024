# 线段树

线段树是一种区间二叉搜索树，能维护和询问区间上的一些性质，采用分治的思想，复杂度 $O(\log{n})$，更详细的原理见 [$oiwiki$](https://oiwiki.com/ds/seg/#%E7%BA%BF%E6%AE%B5%E6%A0%91)。

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

void pushup(int pos) {
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
    pushup(pos);
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
    pushup(pos);
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
    pushup(pos);
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

