#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> V(n), vis(n + 1);
    for (int i = 0; i < k; i++) {
        cin >> V[i];
        vis[V[i]] = 1;
    }

    auto dfs = [&](auto &&self, int u, int fa) -> void {
        for (auto v : adj[u]) {
            if (v != fa) {
                self(self, v, u);
                vis[u] |= vis[v];
            }
        }
    };

    dfs(dfs, V[0], -1);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += vis[i];
    }
    cout << res;

    return 0;
}