#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, x1, x2, k;
    std::cin >> n >> x1 >> x2 >> k;
    x1--;
    x2--;

    if (n <= 3) {
        std::cout << 1 << "\n";
        return;
    }

    int dis = std::min(std::abs(x1 - x2), n - std::abs(x1 - x2));

    int ans = dis + k;

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