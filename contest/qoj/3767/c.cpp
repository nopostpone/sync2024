#include <bits/stdc++.h>

using i64 = long long;

namespace rgs = std::ranges;

void solve()  {
    int n;
    std::cin >> n;

    std::vector<int> l(n), r(n);
    std::vector<std::pair<int, int>> e;

    i64 sl = 0, sr = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
        r[i]++;
        e.emplace_back(l[i], 1);
        e.emplace_back(r[i], -1);
        sl += l[i];
    }
    rgs::sort(e);

    int cur = 0;
    i64 ans = 1e18;

    // auto get = [&](int x) {
    //     i64 res = 0;
    //     res += sl * sl;
    //     res -= 2 * x * sl;

    //     res += sr * sr;
    //     res -= 2 * x * sr;
    //     res += (i64)x * x * (n - cur);

    //     return res;
    // };

    auto get = [&](int x) {

        i64 res = 0;
        for (int i = 0; i < n; i++) {
            if (l[i] > x) {
                res += i64(x - l[i]) * (x - l[i]);
            }
            if (x >= r[i]) {
                res += i64(x - r[i] + 1) * (x - r[i] + 1);
            }
        }

        return res;
    };

    int lo = rgs::min(l);
    int hi = rgs::max(r);

    while (lo + 2 < hi) {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;
        if (get(m1) < get(m2)) {
            hi = m2;
        } else {
            lo = m1;
        }
    }

    for (int i = lo; i <= hi; i++) {
        ans = std::min(ans, get(i));
    }
    std::cout << ans << "\n";

    // for (int j = 0; j < e.size(); j++) {
    //     auto [x, i] = e[j];

    //     cur += i;
    //     if (i == 1) {
    //         sl -= x;
    //     } else {
    //         sr += (x - 1);
    //     }
    //     if (j + 1 < e.size() and e[j + 1].first == x) {
    //         continue;
    //     }

    //     if (j + 1 < e.size()) {
    //         auto [x2, _] = e[j + 1];

    //         int lo = x, hi = x2 - 1;
    //         while (lo + 2 < hi) {
    //             int m1 = lo + (hi - lo) / 3;
    //             int m2 = hi - (hi - lo) / 3;
    //             if (get(m1) < get(m2)) {
    //                 hi = m2;
    //             } else {
    //                 lo = m1;
    //             }
    //         }
    //         for (int d = lo; d <= hi; d++) {
    //             ans = std::min(ans, get(d));
    //         }
    //     }
    // }
    // std::cout << ans << "\n";
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

/*
3
3
6 8
0 2
1 7
2
1 3
2 4
2
1 1
100 100
*/