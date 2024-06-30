// P4779 DIJKSTRA
// https://www.luogu.com.cn/problem/P4779
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const ll inf = pow(2, 31) - 1;
const int N = 1e5 + 10;
struct bian
{
    int v, w;
    bool operator<(const bian &rhs) const
    {
        return w == rhs.w ? v < rhs.v : w > rhs.w;
    }
};
vector<bian> g[N];
priority_queue<bian> pq;
int d[N], n, m;
bitset<N> vis;

void dj(int st)
{
    d[st] = 0;
    pq.push({st, d[st]});
    while (pq.size())
    {
        int u = pq.top().v;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &[v, w] : g[u])
            if (!vis[v] && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}