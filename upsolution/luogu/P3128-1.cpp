// https://www.luogu.com.cn/problem/P3128
// 树剖+差分 O(nlogn)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 1e5 + 10;

int n, m;
vector<int> g[N];
int siz[N], dep[N], top[N], pre[N], a[N], sum[N],  hson[N];
int maxx;

void dfs1(int now, int fa)
{
    int pmax = 0;
    siz[now] = 1;
    pre[now] = fa;
    dep[now] = dep[fa] + 1;
    for (auto &to : g[now])
    {
        if (to == fa)
            continue;
        dfs1(to, now);
        if (siz[to] > siz[pmax])
            pmax = to;
        siz[now] += siz[to];
    }
    if (siz[now] == 1)
        return;
    hson[now] = pmax;
}

void dfs2(int now, int tp)
{
    top[now] = tp;
    if (hson[now])
        dfs2(hson[now], tp);
    for (auto &to : g[now])
    {
        if (to == pre[now] or to == hson[now])
            continue;
        dfs2(to, to);
    }
}

int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            v = pre[top[v]];
        else
            u = pre[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

void getsum(int now)
{
    for (auto &to : g[now])
    {
        if (to == pre[now])
            continue;
        getsum(to);
        sum[now] += sum[to];
    }
    maxx = max(maxx, sum[now]);
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
    dfs1(1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        sum[x]++, sum[y]++;
        sum[lca(x, y)]--;
        sum[pre[lca(x, y)]]--;
    }
    getsum(1);
    cout << maxx;
    
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}