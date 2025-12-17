#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        adj[u].emplace_back(v, d);
    }
    vector<array<i64, 32>> dp(n);
    for (int x = 0; x < n; x++) {
        dp[x].fill(1);
    }
    for (int i = 0; i < 31; i++) {
        for (int x = 0; x < n; x++) {
            for (auto [y, d] : adj[x]) {
                dp[x][i + 1] = max(dp[x][i + 1], dp[y][i] * d);
            }
            if (dp[x][i + 1] > inf) {
                dp[x][i + 1] = inf;
            }
        }
    }

    while (q--) {
        int p, x;
        cin >> p >> x;
        p--;
        int ans = upper_bound(dp[p].begin(), dp[p].end(), x) - dp[p].begin();
        cout << ans << "\n";
    }

    return 0;
}