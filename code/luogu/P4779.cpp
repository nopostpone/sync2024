// https://www.luogu.com.cn/problem/P4779
// dijkstra O((V + E)logE)
// 24.8.18 重写
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const ll inf = (1ll << 31) - 1;

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

    using pii = pair<ll, int>;
    priority_queue<pii, vector<pii>, greater<>> q;
    bitset<100000> vis(0);
    vector<ll> dis(n, inf);

    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto [D, u] = q.top();
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto &&[v, w] : adj[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }

    for (auto &i : dis) {
        cout << i << " ";
    }

    return 0;
}
