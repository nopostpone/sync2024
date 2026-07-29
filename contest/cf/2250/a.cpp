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

    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    if (n % 2 == 1) {
        std::cout << "NO\n";
        return;
    }

    int mini = 1e9, maxj = -1e9;
    for (int i = 0; i < n; i += 2) {
        int j = i + 1;
        mini = std::min(mini, w[i]);
        maxj = std::max(maxj, w[j]);
    }
    // std::cerr << mini << " " << maxj << "\n";
    std::cout << (maxj + 2 <= mini ? "YES" : "NO") << "\n";
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