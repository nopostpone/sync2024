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
    bool ok = false;
    int bigthan2 = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] >= 2) {
            bigthan2++;
        }
        if (a[i] >= 3) {
            ok = true;
        }
    }
    if (bigthan2 >= 2) {
        ok = true;
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
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