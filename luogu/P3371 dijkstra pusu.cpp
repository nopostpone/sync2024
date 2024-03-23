#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const ll inf = pow(2, 31) - 1;
const int N = 1e4 + 10;
struct bian
{
    int v, w;
};
vector<bian> g[N];
ll d[N], n, m;
bitset<N> vis;

void dj(int st)
{
    d[st] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = 1;
        for (int j = 1; j <= n; j++)
            if (vis[u] || (!vis[j] && d[j] < d[u]))
                u = j;
        vis[u] = 1;
        for (auto &[v, w] : g[u])
            if (d[v] > d[u] + w)
                d[v] = d[u] + w;
    }
}

void solve()
{
    int s, u, v, w;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        d[i] = inf;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dj(s);
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}