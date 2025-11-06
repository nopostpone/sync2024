#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> vec(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vec[x].emplace_back(y, z);
    }

    vector<i64> dp(1 << n);
    dp[0] = 1;
    for (u32 s = 0; s < 1 << n; s++) {
        bool valid = true;
        int x = __builtin_popcount(s);
        for (auto [y, z] : vec[x]) {
            int range = (1 << y) - 1;
            if (__builtin_popcount(range & s) > z) {
                valid = false;
            }
        }
        if (not valid) {
            dp[s] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (~s >> i & 1) {
                dp[s | 1 << i] += dp[s];
            }
        }
    }

    cout << dp.back() << "\n";

    return 0;
}