#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using p32 = pair<int, int>;
using p64 = pair<i64, i64>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<p32>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    priority_queue<array<i64, 3>, vector<array<i64, 3>>, greater<>> q;
    q.push({});

    vector dp(n, vector<i64>(n, 1e18));
    while (not q.empty()) {
        auto [d, u, b] = q.top();
        q.pop();

        if (d > dp[u][b]) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            i64 nd = d + w * s[b];
            int nb = min<int>(b, v, [&](int i, int j) {
                return s[i] < s[j];
            });

            if (dp[v][nb] > nd) {
                dp[v][nb] = nd;
                q.push({nd, v, nb});
            }
        }
    }

    i64 ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans << "\n";
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