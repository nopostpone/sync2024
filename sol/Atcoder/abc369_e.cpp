#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }
    }
    vector dp(n + 1, vector<ll>(n + 1, 1e18));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (auto [u, v, w] : edges) {
        dp[u][v] = dp[v][u] = min<ll>(dp[v][u], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;

        vector<int> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
            b[i]--;
        }
        ll ans = 1e18;
        do {
            for (int i = 0; i < (1 << k); i++) {
                ll t = 0;
                int ed = 1;
                for (int j = 0; j < k; j++) {
                    auto [u, v, w] = edges[b[j]];
                    t += w;
                    if ((i >> j) & 1) {
                        t += dp[ed][u];
                        ed = v;
                    } else {
                        t += dp[ed][v];
                        ed = u;
                    }
                }
                t += dp[ed][n];
                ans = min(ans, t);
            }
        } while (next_permutation(b.begin(), b.end()));

        cout << ans << "\n";
    }

    return 0;
}