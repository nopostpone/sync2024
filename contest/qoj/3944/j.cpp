#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int V = 100;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 ans = 0;
    std::array<int, V + 1> cnt {};
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        ans += b[i];
        cnt[a[i] - b[i]]++;
    }

    for (int i = V, rest = m; i >= 0; i--) {
        int coef = std::min(rest, cnt[i]);
        rest -= coef;

        ans += coef * i;
        if (rest <= 0) {
            break;
        }
    }
    std::cout << ans << "\n";
}