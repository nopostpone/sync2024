#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 5e4 + 10;

vector<int> g[N];
int n, root, m;
ll siz[N], ans[N], sum[N];
int b[N];

void dfs(int now, int fa)
{
    siz[now] = 1, ans[now] = 1;
    for (auto &to : g[now])
    {
        if (to == fa)
            continue;
        dfs(to, now);
        siz[now] += siz[to];
        sum[now] += siz[to] * siz[to];
    }
    if (siz[now] == 1)
        return;
    ans[now] = siz[now] * siz[now] - sum[now];
}

void solve()
{
    cin >> n >> root >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    dfs(root, 0);
    for (int i = 1; i <= m; i++)
    {
        cout << ans[b[i]] << endl;
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