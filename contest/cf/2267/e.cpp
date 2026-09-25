#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

auto solve() {
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;


    i64 s0 = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] != s[i + 1]) {
            s0 += i64(i + 1) * (n - i - 1);
        }
    }

    i64 c0 = rgs::count(s, '0');
    i64 c1 = rgs::count(s, '1');
    i64 s1 = c0 * c1;

    i64 ans = (s0 + s1) / 2;
    std::cout << ans << " ";

    auto add = [&](int i, int t) {
        assert(i >= 0 and i + 1 < n);
        s0 += (i64)t * (s[i] != s[i + 1]) * (i + 1) * (n - i - 1);
    };

    for (int _ = 0; _ < q; _++) {
        int p;
        std::cin >> p;
        p--;

        if (s[p] == '1') {
            c1--;
            c0++;
        } else {
            c1++;
            c0--;
        }
        s1 = c1 * c0;

        
        if (p != n - 1) {
            add(p, -1);
        }
        if (p != 0) {
            add(p - 1, -1);
        }
        s[p] ^= 1;
        if (p != n - 1) {
            add(p, 1);
        }
        if (p != 0) {
            add(p - 1, 1);
        }

        ans = (s1 + s0) / 2;

        std::cout << ans << " \n"[_ + 1 == q];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // sieve(3e5);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}

/**
 *      c0 c1 s1 s0
 * 1010 2 2 4 10
 * 0010 3 1 3 7
 * 0110 2 2 4 6
 * 
 * 
 * 
 */