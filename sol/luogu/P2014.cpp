#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    auto adj = vector(n + 1, vector<int>());
    vector<int> b(n + 1);

    for (int i = 1; i <= n; i++) {
        int j;
        cin >> j >> b[i];
        adj[j].push_back(i);
    }

    vector dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
        fill(dp[i].begin() + 1, dp[i].end(), b[i]);
    }

    auto dfs = [&](auto self, int u) -> void {
        for (int v : adj[u]) {
            self(self, v);
            for (int i = m; i >= 1; i--) {
                for (int j = (u == 0 ? 0 : 1); j <= i; j++) {
                    dp[u][i] = max(dp[u][i], dp[u][j] + dp[v][i - j]);
                }
            }
        }
    };
    dfs(dfs, 0);

    cout << dp[0][m];

    return 0;
}