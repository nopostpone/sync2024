#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + h[i];
    }

    vector dp(n + 1, vector<i64>(n + 1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int p = 0;
        for (int j = 0; j < i; j++) {
            while (p <= n and pre[p] < 2 * pre[j] - pre[i]) {
                p++;
            }
            dp[i][j] = min(dp[i][j], dp[j][p] + i - (j + 1));
        }
        for (int j = n - 1; j >= 0; j--) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }

    cout << dp[n][0] << "\n";

    return 0;
}