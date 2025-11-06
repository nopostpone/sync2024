// https://www.luogu.com.cn/problem/P3371
// dijkstra O(n^2) 做法
// 24.8.18 重写一下，更整洁点
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr ll inf = (1LL << 31) - 1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, s;
    cin >> n >> m >> s;
    s--;

    vector<vector<pair<int, ll>>> adj;
    adj.assign(n, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    vector<ll> dist(n, inf);
    bitset<10005> vis(0);

    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = 0;
        for (int j = 0; j < n; j++) {
            if (vis[u] || (!vis[j] and dist[j] < dist[u])) {
                u = j;
            }
        }
            vis[u] = 1;
            for (auto &&[v, w] : adj[u]) {
                dist[v] = min<ll>(dist[v], dist[u] + w);
            }
    }

    for (auto &i : dist) {
        cout << i << " ";
    }

    return 0;
}