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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto get = [&](int i, int x) {
        int res = 0;
        if (i != 0) {
            res += std::abs(a[i + 1] - x);
        }
        if (i != n - 1) {
            res += std::abs(a[i - 1] - x);
        }
        return res;
    };
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = get(i, a[i]);
    }
    
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