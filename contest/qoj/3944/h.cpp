#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int inf = 2e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> t(n), x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i] >> x[i];
    }

    int end = inf;
    std::vector<int> ans(n);
    bool ok = true;
    for (int i = n - 1; i >= 0; i--) {
        end = std::min(end, t[i]);
        ans[i] = end - x[i] + 1;
        end -= x[i];
        if (ans[i] < 1) {
            ok = false;
            break;
        }
    }

    if (not ok) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << " \n"[i == n - 1];
        }
    }
}