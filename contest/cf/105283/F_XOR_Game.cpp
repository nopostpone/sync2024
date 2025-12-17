#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> dp(m, inf);
    dp[0] = 1 - (s[0][0] - '0');
    for (int j = 1; j < m; j++) {
        if (s[0][j] != s[0][j - 1]) {
            break;
        }
        dp[j] = dp[j - 1];
    }
    for (int i = 1; i < n; i++) {
        vector<int> ndp(m, inf);
        for (int j = 0; j < m; j++) {
            if (j and s[i][j] == s[i][j - 1]) {
                ndp[j] = min(ndp[j], ndp[j - 1]);
            }
            ndp[j] = min(ndp[j], dp[j] + 1 - (s[i][j] - '0'));
        }
        dp = move(ndp);
    }

    auto ans = dp[m - 1];
    if (ans >= inf) {
        ans = -1;
    }
    cout << ans << "\n";
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