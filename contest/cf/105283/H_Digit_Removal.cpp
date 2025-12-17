#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    string a, b;
    cin >> a >> b;

    const int n = a.size();

    array<i64, 5> dp {};
    dp[0] = 1;

    i64 ans = 0;

    for (int i = 0; i < n; i++) {

        array<i64, 5> ndp {};
        for (int j = 0; j < 5; j++) {
            if (dp[j] == 0) {

            }
            auto kept = i - j;
            if (j < 4) {
                ndp[j + 1] += dp[j];
            }
            if (kept < m) {

            }
        }
        dp = move(ndp);
    }
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