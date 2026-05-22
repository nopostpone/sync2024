#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

using std::cerr;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    auto vy = y;
    rgs::sort(vy);
    vy.erase(std::unique(vy.begin(), vy.end()), vy.end());

    auto vx = x;
    rgs::sort(vx);
    vx.erase(std::unique(vx.begin(), vx.end()), vx.end());

    std::vector<int> ord(n);
    rgs::iota(ord, 0);
    rgs::sort(ord, [&](int i, int j) {
        return x[i] < x[j];
    });

    // for (auto i : ord) {
    //     std::cerr << x[i] << " " << y[i] << "\n";
    // }

    std::vector<int> l1(n), l2(n), r1(n), r2(n);
    l1[0] = l2[0] = y[ord[0]];
    r1[n - 1] = r2[n - 1] = y[ord[n - 1]];

    for (int i = 1; i < n; i++) {
        int u = ord[i];
        l1[i] = std::min(l1[i - 1], y[u]);
        l2[i] = std::max(l2[i - 1], y[u]);
    }
    for (int i = n - 2; i >= 0; i--) {
        int u = ord[i];
        r1[i] = std::min(r1[i + 1], y[u]);
        r2[i] = std::max(r2[i + 1], y[u]);

        // cerr << i << " " << r1[i] << " " << r2[i] << "\n";
    }

    // for (int i = 0; i < n; i++) {
    //     std::cerr << l1[i] << " " << l2[i] << " " << r1[i] << " " << r2[i] << "\n";
    // }

    i64 ans = 0;
    int i = 0;
    for (auto e : vx) {
        if (e == vx.back()) {
            break;
        }
        while (i < n and x[ord[i]] <= e) {
            i++;
        }
        int lo = std::max(l1[i - 1], r1[i]);
        int hi = std::min(l2[i - 1], r2[i]);

        if (lo < hi) {
            int l = std::lower_bound(vy.begin(), vy.end(), lo) - vy.begin();
            int r = std::lower_bound(vy.begin(), vy.end(), hi) - vy.begin();

            // std::cerr << e << " " << lo << " " << hi << " " << l << " " << r << "\n";
            ans += r - l;
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