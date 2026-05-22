#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    i64 ans = 0;
    if (b < 3 * a) {
        ans = (i64)b * (n / 3);
        // std::cerr << ans << "\n";
        n %= 3;

        ans += std::min(b, a * n);
    } else {
        ans = (i64)a * n;
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