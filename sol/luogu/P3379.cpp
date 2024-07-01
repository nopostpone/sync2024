#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 5e6 + 10;

vector<int> g[N];
int n, root, m;
int siz[N], dfn[N], top[N], hson[N], bot[N], pre[N], dep[N];

void Adfs(int now, int fa)
{
    int maxsiz = 0;
    siz[now] = 1;
    pre[now] = fa;
    for (auto &to : g[now])
    {
        if (to == fa)
            continue;
        dfs(to, now);
        if (siz[to] > siz[maxsiz])
            maxsiz = to;
        siz[now] += siz[to];
        sum[now] += siz[to] * siz[to];
    }
    if (siz[now] == 1)
        return;
    hson[now] = maxsiz;
}

void Bdfs(int now, int tp)
{
    top[now] = tp;
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
        cout << lca(u, v);
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