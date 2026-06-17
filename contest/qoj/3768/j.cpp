#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

namespace rgs = std::ranges;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> t(n);
    for (int i = 1; i < n; i++) {
        std::cin >> t[i];
    }

    std::cout << std::accumulate(t.begin(), t.end(), i64()) + double(k) / 4 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(3);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}