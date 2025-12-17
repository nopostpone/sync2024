#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        ranges::sort(adj[i]);
    }

    vector<int> path;
    bool found = false;
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int u) {
        if (found) {
            return;
        }
        if (u == y) {
            for (int i : path) {
                cout << i + 1 << " ";
            }
            cout << "\n";
            found = true;
            return;
        }

        for (int v : adj[u]) {
            if (vis[v]) {
                continue;
            }

            vis[v] = true;
            path.push_back(v);
            self(self, v);
            path.pop_back();
        }
    };
    path.push_back(x);
    vis[x] = true;
    dfs(dfs, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}