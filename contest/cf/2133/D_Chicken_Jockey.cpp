#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = min(i, h[i]);
    }

    array<i64, 2> dp;
    dp[0] = 1;
    dp[1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        array<i64, 2> ndp;
        ndp[0] = max(dp[0], dp[1]) + (i != 0);
        ndp[1] = dp[0] + d[i + 1] - (i != 0);
        dp = move(ndp);
    }

    i64 ans = accumulate(h.begin(), h.end(), i64());
    ans -= ranges::max(dp) - 1;

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