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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> f1(n + 1), f2(n + 1);
    for (int i = 0; i < n; i++) {
        f1[i + 1] = f1[i] + (a[i] > 1 ? -1 : 1);
        f2[i + 1] = f2[i] + (a[i] > 2 ? -1 : 1);

        // std::cerr << f1[i + 1] << " " << f2[i + 1] << "\n";
    }

    std::vector<int> g(n);
    g[n - 1] = n - 1;
    for (int i = n - 1; i > 0; i--) {
        if (f2[i - 1] > f2[g[i]]) {
            g[i - 1] = i - 1;
        } else {
            g[i - 1] = g[i];
        }
    }

    for (int i = 1; i + 1 < n; i++) {
        if (f1[i] >= 0 and g[i] != i) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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