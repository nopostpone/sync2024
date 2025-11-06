#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector adj(n, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector dp(n, vector<int>(m + 1));

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto [v, w] : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);

            for (int i = m; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                    dp[u][i] = max(dp[u][i],
                                    dp[u][i - j - 1] + dp[v][j] + w);
                }
            }
        }
    };
    dfs(dfs, 0, -1);

    cout << dp[0][m];

    return 0;
}