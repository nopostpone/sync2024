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

    std::array<int, 3> c {};
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        c[x]++;
    }

    int ans = c[0];

    auto x = std::min(c[1], c[2]);
    ans += x;
    c[1] -= x;
    c[2] -= x;
    ans += c[1] / 3 + c[2] / 3;
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