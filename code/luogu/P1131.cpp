#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, r;
    cin >> n >> r;

    r--;
    
    vector adj(n, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dp(n);
    ll ans{};

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto [v, w] : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            dp[u] = max(dp[u], dp[v] + w);
        }
        for (auto [v, w] : adj[u]) {
            if (v == fa) {
                continue;
            }
            ans += dp[u] - (dp[v] + w);
        }
    };
    dfs(dfs, r, -1);

    cout << ans << "\n";

    return 0;
}