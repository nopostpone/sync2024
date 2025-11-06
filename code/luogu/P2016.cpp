#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector adj(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        while (k--) {
            int v;
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    vector dp(n, array<int, 2>());
    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
    }

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);

            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    };

    dfs(dfs, 0, -1);
    cout << min(dp[0][0], dp[0][1]);

    return 0;
}