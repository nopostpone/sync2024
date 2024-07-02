// https://www.luogu.com.cn/problem/P3379
// 树剖LCA
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 5e6 + 10;

vector<int> g[N];
int n, root, m;
int siz[N], top[N], hson[N], pre[N], dep[N];

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
    for (auto &to : g[now])
    {
        if (to == pre[now])
            continue;
        if (to != hson[now])
            Bdfs(to, to);
        else
            Bdfs(to, tp);
    }
}

int lca(int u, int v)
{
    if (u == v)
        return u;
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

void solve()
{
    cin >> n >> m >> root;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Adfs(root, 0);
    Bdfs(root, root);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
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