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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    if (a == b) {
        std::cout << 0 << "\n";
        return;
    }

    std::array<int, 4> cnt {};
    for (int i = 0; i < n; i++) {
        cnt[a[i] + b[i] * 2]++;
    }
    // for (int i = 0; i < 4; i++) {
    //     std::cout << std::bitset<2>(i) << " " << cnt[i] << "\n";
    // }
    int ans = -1;
    
    if (cnt[1] % 2 == 1) {
        ans = 1;
    } else if (cnt[1] > 0 or (cnt[3] > 0 and cnt[0] > 0)) {
        ans = 2;
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