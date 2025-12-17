#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int x = 0; x < n; x++) {
        ranges::sort(adj[x]);
    }
    auto dfs = [&](auto &&self, int x, int p) -> void {
        cout << x + 1 << " ";
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(self, y, x);
            cout << x + 1 << " ";
        }
    };
    dfs(dfs, 0, -1);

    return 0;
}