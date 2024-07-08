// https://www.luogu.com.cn/problem/U318445
// 重链剖分
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

vector<int> g[N];
int n, root, m, qry, s0, d0;
int siz[N], top[N], hson[N], pre[N], dep[N], dfn[N], a[N], aa[N], bottom[N];
int jiediandfn;
ll P;
vector<ll> res;
vector<pair<int, int>> rs;

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

int smove(int s)
{
    int u = s;
    if (siz[u] == 1)
        return 1;
    for (auto &to : g[u])
    {
        if (to == pre[u])
            continue;
        else
        {
            if (u == s or siz[to] > siz[u])
                u = to;
            else if (u != s and siz[to] == siz[u])
                u = max(u, to);
        }
    }
    return u;
}

int dmove(int d)
{
    int u = d;
    if (u == 1)
        return n;
    for (auto &v : g[u])
    {
        if (u != d)
            u = min(u, v);
        else
            u = v;
    }
    return u;
}

pair<int, int> treeupdate(int s, int d, int t)
{
    int u = s, v = d;
    u = smove(u);
    v = dmove(v);
    v = dmove(v);
    return {u, v};
}

int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = pre[top[u]];
    }
    if (dep[u] < dep[v])
        return u;
    return v;
}

int getdis(int u, int v)
{
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

void solve()
{
    cin >> n >> qry >> s0 >> d0;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Adfs(1, 0);
    Bdfs(1, 1);
    rs.push_back({s0, d0});
    for (int i = 1; i <= N; i++)
    {
        rs.push_back(treeupdate(rs.back().first, rs.back().second, rs.size()));
    }
    for (int i = 1; i <= qry; i++)
    {
        int t;
        cin >> t;
        res.push_back(getdis(rs[t].first, rs[t].second));
    }
    for (auto &i : res)
        cout << i << endl;

    // for (auto &&[i, j] : rs)
    //     cout << i << ' ' << j << endl;
    // cout<<getdis(1,2);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}