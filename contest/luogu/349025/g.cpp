#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    double ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        ans += (y[i] + y[i + 1]) * (x[i + 1] - x[i]);
    }
    ans /= 2;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(6);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}