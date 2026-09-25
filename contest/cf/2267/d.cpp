#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

auto solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        p[a[i]] = i;
    }

    int even = (n + 1) / 2;
    int odd = n / 2;
    for (int x = 0; x < n; x++) {
        if (odd > even and (p[x] % 2 == 0)) {
            return false;
        }
        if (even > odd and (p[x] % 2 == 1)) {
            return false;
        }
        ((p[x] % 2) ? odd : even)--;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // sieve(3e5);

    int t;
    std::cin >> t;

    while (t--) {
        std::cout << (solve() ? "YES" : "NO") << "\n";
    }
}