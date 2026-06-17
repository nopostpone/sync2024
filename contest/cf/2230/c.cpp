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

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    if (c.back() < 2) {
        std::cout << 0 << "\n";
        return;
    }

    int ones = 0;
    i64 bones = 0;
    i64 bsum = 0;
    for (auto x : c) {
        if (x == 1) {
            ones++;
        } else {
            bones += x / 2 - 1;
            bsum += x;
        }
    }

    i64 ans = 0;
    if (ones == n - 1) {
        ans = bsum + std::min(bones + 1, (i64)ones);
    } else {
        ans = bsum + std::min(bones, (i64)ones);
    }
    if (ans < 3) {
        ans = 0;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
