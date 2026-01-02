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

    int n, m;
    cin >> n >> m;

    vector b(n, basic_string(n, false));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        b[u][v] = b[v][u] = true;
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](auto &&self, int x, int p) -> vector<vector<i64>> {
        vector dp(n, vector<i64>(1 << n));
        for (int i = 0; i < n; i++) {
            for (int s = 0; s < 1 << n; s++) {
                if (s >> i & 1) {
                    dp[i][s] = 1;
                }
            }
        }
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            auto g = self(self, y, x);

            for (int i = 0; i < n; i++) {
                vector<i64> f(1 << n);
                for (int j = 0; j < n; j++) {
                    if (not b[i][j]) {
                        continue;
                    }
                    for (int s = 0; s < 1 << n; s++) {
                        f[s] += dp[i][s] * g[j][s];
                    }
                }
                dp[i] = move(f);
            }
        }

        return (dp);
    };
    auto dp = dfs(dfs, 0, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int s = 0; s < 1 << n; s++) {
                if (~s >> j & 1) {
                    dp[i][s | 1 << j] -= dp[i][s];
                }
            }
        }
    }
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i].back();
    }
    cout << ans << "\n";

    return 0;
}