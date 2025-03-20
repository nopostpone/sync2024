#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector dp(n, vector<i64>(n));
    for (int r = 2; r < n; r++) {
        for (int l = r - 2; l >= 0; l--) {
            for (int i = l + 1; i < r; i++) {
                dp[l][r] = max(dp[l][r], dp[l + 1][i - 1] + dp[i + 1][r - 1] + a[l] * a[i] * a[r]);
            }
            for (int i = l; i < r; i++) {
                dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}