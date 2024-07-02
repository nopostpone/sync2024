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
int siz[N], top[N], hson[N], pre[N], dep[N], dfn[N], a[N], aa[N], bottom[N];
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
    s[lst].add += s[pos].add, s[rst].add += s[pos].add;
    s[pos].add = 0;
}

void pushup(ll pos)
{
    s[pos].sum = s[lst].sum + s[rst].sum;
    s[pos].sum %= P;
}

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r, s[pos].add = 0;
    if (l == r)
    {
        s[pos].sum = a[l] % P;
        return;
    }
    ll m = l + ((r - l) >> 1);
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
}

void add(ll x, ll y, ll pos, ll val)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        s[pos].add = (s[pos].add + val) % P;
        s[pos].sum = (s[pos].sum + (s[pos].r - s[pos].l + 1) * val) % P;
        return;
    }
    pushdown(pos);
    ll m = (s[pos].l + s[pos].r) >> 1;
    if (x <= m)
        add(x, y, lst, val);
    if (y > m)
        add(x, y, rst, val);
    pushup(pos);
}

ll getsum(ll x, ll y, ll pos)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        return (s[pos].sum) % P;
    }
    pushdown(pos);
    ll m = (s[pos].l + s[pos].r) >> 1;
    ll ans = 0;
    if (x <= m)
        ans = (ans + getsum(x, y, lst)) % P;
    if (y > m)
        ans = (ans + getsum(x, y, rst)) % P;
    return ans;
}

void updatelujing(int u, int v, int val)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        add(dfn[top[u]], dfn[u], 1, val);
        u = pre[top[u]];
    }
    add(dfn[u], dfn[v], 1, val);
}

ll asklujing(int u, int v)
{
    ll ans = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        ans += getsum(dfn[top[u]], dfn[u], 1);
        ans %= P;
        u = pre[top[u]];
    }
    ans += getsum(dfn[u], dfn[v], 1);
    ans %= P;
    return ans;
}

void updatezishu(int x, int z)
{
    add(dfn[x], bottom[x], 1, z);
}

ll askzishu(int x)
{
    return getsum(dfn[x], bottom[x], 1) % P;
}

void solve()
{
    cin >> n >> m >> root >> P;
    for (int i = 1; i <= n; i++)
        cin >> aa[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Adfs(root, 0);
    Bdfs(root, root);
    for (int i = 1; i <= n; i++)
        a[dfn[i]] = aa[i];
    build(1, n, 1);
    while (m--)
    {
        int opt, x, y = 0, z = 0;
        cin >> opt;
        if (opt == 1)
        {
            cin >> x >> y >> z;
            updatelujing(x, y, z);
        }
        else if (opt == 2)
        {
            cin >> x >> y;
            res.push_back(asklujing(x, y));
        }
        else if (opt == 3)
        {
            cin >> x >> z;
            updatezishu(x, z);
        }
        else if (opt == 4)
        {
            cin >> x;
            res.push_back(askzishu(x));
        }
        else
        {
            cout << "?" << endl;
            exit(0);
        }
    }
    for (auto &i : res)
        cout << i % P << endl;
}

// 调线段树用-P3372
void tiaoshi()
{
    P = 0x3f3f3f3f3f;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y, k;
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            cin >> k;
            add(x, y, 1, k);
        }
        else if (opt == 2)
            res.push_back(getsum(x, y, 1));
    }
    for (auto &i : res)
        cout << i << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}