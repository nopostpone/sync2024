#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr double e = 0.01 + 1e-6, z = 0.995;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::array<double, 3>> p(2 * n);

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            const int u = x * 10 + y;
            if (u < n) {
                p[u] = {e * x, e * y, 0};
                p[u + n] = {e * x, e * y, z};
            }
        }
    }

    std::cout << 2 * n << "\n";
    for (auto [x, y, z] : p) {
        std::cout << x << " " << y << " " << z << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::cout << std::fixed << std::setprecision(9);

    while (t--) {
        solve();
    }
}