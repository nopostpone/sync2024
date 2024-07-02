// https://www.luogu.com.cn/problem/P3128
// 树剖+线段树 O(nlognlogn)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 1e5 + 10;

vector<int> g[N];
int n, root, m;
int siz[N], top[N], hson[N], pre[N], dep[N], dfn[N], a[N], bottom[N];
int jiediandfn;
ll P;
struct SegmentTreeNode
{
    ll l, r, mx, add;
} s[N * 4];
vector<ll> res;

void Adfs(int now, int fa)
{
    int pmax = 0;
    siz[now] = 1;
    pre[now] = fa;
    dep[now] = dep[fa] + 1;
    for (auto &to : g[now])
    {
        if (to == fa)
            continue;
        Adfs(to, now);
        if (siz[to] > siz[pmax])
            pmax = to;
        siz[now] += siz[to];
    }
    if (siz[now] == 1)
        return;
    hson[now] = pmax;
}

void Bdfs(int now, int tp)
{
    top[now] = tp;
    dfn[now] = ++jiediandfn;
    if (siz[now] == 1)
        bottom[now] = dfn[now];
    if (hson[now])
    {
        Bdfs(hson[now], tp);
        bottom[now] = bottom[hson[now]];
    }
    for (auto &to : g[now])
    {
        if (to == pre[now] or to == hson[now])
            continue;

        Bdfs(to, to);
        bottom[now] = max(bottom[now], bottom[to]);
    }
}

void pushdown(ll pos)
{
    s[lst].mx += s[pos].add, s[rst].mx += s[pos].add;
    s[lst].add += s[pos].add, s[rst].add += s[pos].add;
    s[pos].add = 0;
}

void pushup(ll pos)
{
    s[pos].mx = max(s[lst].mx, s[rst].mx);
}

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r, s[pos].add = 0;
    if (l == r)
    {
        s[pos].mx = a[l];
        return;
    }
    ll m = l + ((r - l) >> 1);
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
}

void add(ll x, ll y, ll pos)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        s[pos].mx++;
        s[pos].add++;
        return;
    }
    pushdown(pos);
    ll m = (s[pos].l + s[pos].r) >> 1;
    if (x <= m)
        add(x, y, lst);
    if (y > m)
        add(x, y, rst);
    pushup(pos);
}

void updatelujing(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        add(dfn[top[u]], dfn[u], 1);
        u = pre[top[u]];
    }
    add(dfn[u], dfn[v], 1);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Adfs(1, 0);
    Bdfs(1, 1);
    build(1, n, 1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        updatelujing(x, y);
    }
    cout << s[1].mx;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}