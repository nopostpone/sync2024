#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int a[4];
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a + 4, std::greater());

    std::cout << a[0] * a[1] - a[2] * a[3] << "\n";
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