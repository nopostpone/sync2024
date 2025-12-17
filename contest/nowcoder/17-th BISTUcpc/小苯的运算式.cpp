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

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = -a[i][0];
    }

    array<i64, 2> dp {};
    for (int i = n - 1; i >= 0; i--) {
        array<i64, 2> ndp;
        ndp[0] = max(dp[0], dp[1] + a[i][0]);
        ndp[1] = max(dp[1], dp[0] + a[i][1]);
        dp = move(ndp);
    }

    cout << dp[0] << "\n";
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