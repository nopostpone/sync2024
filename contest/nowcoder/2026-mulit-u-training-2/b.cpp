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

    std::array<int, 31> b {};
    auto ins = [&](int x) {
        for (int i = 30; i >= 0; i--) {
            if (~x >> i & 1) {
                continue;
            }
            if (b[i] == 0) {
                b[i] = x;
                return;
            }
            x ^= b[i];
        }
    };

    std::vector<int> a(n);
    int s1 = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        s1 ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        ins(a[i] & (~s1));
    }
    i64 ans = 0;
    for (int i = 30; i >= 0; i--) {
        if ((ans ^ b[i]) > ans) {
            ans ^= b[i];
        }
    }

    ans = 2 * ans + s1;

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
