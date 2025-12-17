#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    // vector<int> dp(x + y + 1);
    // for (int i = 0; i < n; i++) {
    //     auto odp = dp;
    //     if (i < y) {
    //         for (int j = 0; j <= x + i; j++) {
    //             dp[j] = max(odp[j], odp[j] + j + 1);
    //         }
    //     } else {
    //         for (int j = 0; j < x + y; j++) {
    //             dp[j] = max(odp[j], odp[j + 1] + j + 1);
    //         }
    //     }
    //     // for (int i = 0; i < x + y; i++) {
    //     //     cerr << dp[i] << " \n"[i == x + y - 1];
    //     // }
    // }
    // cout << *max_element(dp.begin(), dp.end()) << "\n";

    i64 ans = 0;

    n = min(n, x + y + y);

    for (int i = 0; i < n; i++) {
        if (i < y) {
            x++;
        }
        if (x < 0) {
            break;
        }
        if (n - i <= x) {
            ans += x;
            x--;
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