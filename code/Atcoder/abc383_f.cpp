#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, k;
    cin >> n >> x >> k;

    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
        a[i][2]--;
    }

    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        vec[a[i][2]].push_back(i);
    }

    vector<i64> dp(x + 1, -inf);
    dp[0] = 0;
    for (int c = 0; c < n; c++) {
        auto odp = dp;
        for (int i : vec[c]) {
            auto &[p, u, _] = a[i];

            for (int j = x; j >= p; j--) {
                dp[j] = max(dp[j], odp[j - p] + u + k);
                dp[j] = max(dp[j], dp[j - p] + u);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}