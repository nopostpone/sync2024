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

    std::vector<int> l(n), r(n), u(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i] >> u[i] >> v[i];
        // l[i]--;
        // r[i]--;
        // u[i]--;
        // v[i]--;
    }

    auto check = [&](int i, int rk, int m) {
        if (l[i] <= rk and rk <= r[i]) {
            return false;
        }
        rk = m - rk + 1;
        if (u[i] <= rk and rk <= v[i]) {
            return false;
        }
        return true;
    };

    int ans = 0;
    for (int siz = 1; siz <= n; siz++) {

        bool ok = true;
        for (int j = 0, p = 0; j < siz; j++) {
            bool found = false;
            while (not found and p < n) {
                if (check(p, j + 1, siz)) {
                    found = true;
                }
                p++;
            }
            if (not found) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = siz;
        }
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
