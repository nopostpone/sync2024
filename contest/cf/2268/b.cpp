#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr bool check(int x) {
    return (__builtin_popcount(x) % 2) == 0;
}

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];

        // std::cerr << check(a[i]) << " \n"[i == n - 1];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += check(a[i]);
    }
    std::cout << ans << " ";

    while (q--) {
        int p, x;
        std::cin >> p >> x;
        p--;

        ans -= check(a[p]);
        a[p] = x;
        ans += check(a[p]);

        std::cout << ans << " \n"[!q];
    }
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

/**
 *                  even
 * 1111 0001 0101 -> 2
 * 1111 0001 0000 -> 2
 * 1010 0001 0000 -> 2
 * 1010 0000 0000 -> 3
 */

/**
 * 0 0000
 * 3 0011
 * 6 0110
 * 9 1001
 * 12 1100
 * 15 1111
 * 
 * even 1
 */
