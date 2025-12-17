#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int v1 = -1, v2 = -1, v3 = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 2) {
            v1 = i;
            v2 = adj[v1][0];
            v3 = adj[v1][1];
            break;
        }
    }

    if (v1 == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<int> mod(n);
    vector<array<int, 2>> edges;
    auto dfs = [&](this auto &&self, int x, int p) -> void {
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            if (mod[x]) {
                edges.push_back({x, y});
            } else {
                edges.push_back({y, x});
                mod[y] = 1;
            }
            self(y, x);
        }
    };

    edges.push_back({v1, v2});
    dfs(v2, v1);
    edges.push_back({v3, v1});
    mod[v3] = 1;
    dfs(v3, v1);

    for (auto [x, y] : edges) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}