#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, x;
    std::cin >> n >> k >> x;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    int y = std::find(p.begin(), p.end(), x) - p.begin();

    k = (k - y + n) % n;

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[(i + k) % n] = p[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}