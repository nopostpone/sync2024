#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    constexpr int inf = 1e9;

    auto check = [&](double x) {
        vector<double> dp(w + 1, -inf);
        dp[0] = 0;
        for (auto [e, t] : a) {
            for (int j = w; ~j; j--) {
                int k = min(w, j + e);
                double tem = t - e * x;
                dp[k] = max(dp[k], dp[j] + tem);
            }
        }
        return dp[w] >= 0;
    };
    
    double lo = 0, hi = 1000;
    while (hi - lo > 1e-5) {
        double m = (lo + hi) / 2;
        if (check(m)) {
            lo = m;
        } else {
            hi = m;
        }
    }

    int ans = hi * 1000;
    cout << ans << "\n";    

    return 0;
}