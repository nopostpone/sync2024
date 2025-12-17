// https://www.luogu.com.cn/problem/P3258
// 重链剖分+线段树维护路径信息
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 3e5 + 100;

int n;
ll a[N], dfn[N], siz[N], dep[N], pre[N], top[N], bottom[N], hson[N];
int bbh;
vector<int> g[N];
struct segtree
{
    ll l, r, pos, sum, add;
} s[N * 4];

void pushdown(ll pos)
{
    s[lst].sum += s[pos].add * (s[lst].r - s[lst].l + 1);
    s[rst].sum += s[pos].add * (s[rst].r - s[rst].l + 1);
    s[lst].add += s[pos].add;
    s[rst].add += s[pos].add;
    s[pos].add = 0;
}

void pushup(ll pos)
{
    s[pos].sum += s[lst].sum + s[rst].sum;
}

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r, s[pos].sum = s[pos].add = 0;
    if (l == r)
    {
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
}

void upd(ll x, ll y, ll pos, ll k)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        s[pos].sum += (s[pos].r - s[pos].l + 1) * k;
        s[pos].add += k;
        return;
    }
    pushdown(pos);
    ll m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        upd(x, y, lst, k);
    if (m < y)
        upd(x, y, rst, k);
    pushup(pos);
    return;
}

ll getsum(ll x, ll y, ll pos)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        return s[pos].sum;
    }
    pushdown(pos);
    ll m = s[pos].l + s[pos].r >> 1;
    ll ans = 0;
    if (x <= m)
        ans += getsum(x, y, lst);
    if (m < y)
        ans += getsum(x, y, rst);
    return ans;
}

void dfs1(int now, int fa)
{
    int pmax = 0;
    siz[now] = 1;
    dep[now] = dep[fa] + 1;
    pre[now] = fa;
    for (auto &to : g[now])
    {
        if (to == fa)
            continue;
        dfs1(to, now);
        siz[now] += siz[to];
        if (siz[to] > siz[pmax])
            pmax = to;
    }
    if (siz[now] != 1)
        hson[now] = pmax;
}

void dfs2(int now, int tp)
{
    dfn[now] = ++bbh;
    top[now] = tp;
    if (siz[now] == 1)
        bottom[now] = now;
    else
        dfs2(hson[now], tp), bottom[now] = bottom[hson[now]];
    for (auto &to : g[now])
    {
        if (to == pre[now] or to == hson[now])
            continue;
        dfs2(to, to);
        bottom[now] = max(bottom[now], bottom[to]);
    }
}

void tupd(int st, int ed)
{
    upd(dfn[ed], dfn[ed], 1, -1);
    while (top[st] != top[ed])
    {
        if (dep[top[st]] < dep[top[ed]])
            swap(st, ed);
        upd(dfn[top[st]], dfn[st], 1, 1);
        st = pre[top[st]];
    }
    upd(dfn[st], dfn[ed], 1, 1);
}

ll query(int x)
{
    return getsum(dfn[x], dfn[x], 1);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1,n,1);
    for (int i = 1; i < n; i++)
    {
        tupd(a[i], a[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << query(i) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}