#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 4e18;

struct Node {
    int x, y;
    i64 cost;
};

void solve() {
    int n, c1, c2;
    cin >> n >> c1 >> c2;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector dp(n + 1, vector<Node>(2));
    for (int i = 0; i < 2; i++) {
        dp[0][i] = {0, 0, 0};
    }

    for (int i = 1; i <= n; i++) {
        int u = a[i - 1];
        int v = b[i - 1];

        // 0
        dp[i][0] = {u, v, inf};
        for (int k = i - 1; k >= 0; k--) {
            for (auto [ou, ov, oc] : dp[k]) {
                if (u >= ou and v >= ov and u + v >= ou + ov) {
                    dp[i][0].cost = min(dp[i][0].cost, oc + 1ll * (i - k - 1) * c1);
                }
            }
        }

        // 1
        dp[i][1] = {v, u, inf};
        for (int k = i - 1; k >= 0; k--) {
            for (auto [ou, ov, oc] : dp[k]) {
                if (v >= ou and u >= ov and u + v >= ou + ov) {
                    dp[i][1].cost = min(dp[i][1].cost, oc + 1ll * (i - k - 1) * c1 + c2);
                }
            }
        }
    }
    
    i64 ans = inf;
    for (int i = n; i >= 0; i--) {
        for (auto [u, v, c] : dp[i]) {
            ans = min(ans, c + 1ll * (n - i) * c1);
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}