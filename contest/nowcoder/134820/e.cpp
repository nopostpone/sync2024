#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

using std::cerr;

constexpr int E = 31;

int f(int m, int k) {
    if (m == 0) {
        return 0;
    }
    return ((m - 1) & k) != k;
}

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::array<int, E> c0 {};
    auto add = [&](int i, int t) {
        for (int b = 0; b < E; b++) {
            if (~a[i] >> b & 1) {
                c0[b] += t;
            }
        }
    };

    for (int i = 0; i < n; i++) {
        add(i, 1);
    }

    for (int _ = 0; _ < q; _++) {
        int o;
        std::cin >> o;

        if (o == 1) {
            int x, y;
            std::cin >> x >> y;
            x--;
            add(x, -1);
            a[x] = y;
            add(x, 1);
        } else {
            int k;
            std::cin >> k;

            int tot = f(n, k);
            int ans = 0;
            for (int b = 0; b < E; b++) {
                int res = f(c0[b], k);
                ans += (res xor tot) << b;
            }
            std::cout << ans << "\n";
        }
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