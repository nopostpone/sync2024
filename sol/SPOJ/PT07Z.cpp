// https://www.spoj.com/problems/PT07Z/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e4 + 100;

int n;
vector<int> g[N];
int dep[N];

void dfs(int now, int fa)
{
    dep[now] = dep[fa] + 1;
    for (auto &i : g[now])
    {
        if (i == fa)
            continue;
        dfs(i, now);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[0] = -1;
    dfs(1, 0);
    pair<int, int> maxdep({0, 0});
    for (int i = 1; i <= n; i++)
        if (dep[i] > maxdep.second)
            maxdep.first = i, maxdep.second = dep[i];
    memset(dep, 0, sizeof(dep));
    dep[0] = -1;
    dfs(maxdep.first, 0);
    sort(dep + 1, dep + 1 + n, greater<int>());
    cout << dep[1];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}