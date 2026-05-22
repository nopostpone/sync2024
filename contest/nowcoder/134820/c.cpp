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

    int base = rgs::count_if(a, [](int x) {
        return x % 2 == 1;
    });

    auto work = [&](bool st) {
        std::vector<int> f {0};
        for (int i = st; i < n; i += 2) {
            if (a[i] % 2 == 1) {
                f.push_back(-1);
            } else {
                f.push_back(1);
            }
        }
        int ans = 0;
        int res = 0;
        for (int i = 0; i < f.size(); i++) {
            res = std::max(res + f[i], 0);
            ans = std::max(ans, res);
        }
        return ans;
    };

    int ans = std::max(work(0), work(1)) + base;

    std::cout << (ans > n / 2 ? "Alice" : "Bob") << "\n";

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