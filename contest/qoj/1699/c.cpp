#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;

    vector a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    array<i64, 16> dp;
    dp.fill(inf);
    dp[0] = 0;
    for (int s = 0; s < 16; s++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int t = 0;
                if (x <= n / 2 and y <= n / 2) {
                    t |= 1;
                }
                if (x <= n / 2 and y >= n / 2) {
                    t |= 2;
                }
                if (x >= n / 2 and y <= n / 2) {
                    t |= 4;
                }
                if (x >= n / 2 and y >= n / 2) {
                    t |= 8;
                }

                dp[s | t] = min(dp[s | t], dp[s] + a[x][y]);
            }
        }
    }
    cout << dp.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}