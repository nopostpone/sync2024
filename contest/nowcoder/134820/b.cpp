#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int p = -1;
    i64 aff = 1e18;

    i64 pre = 0;
    for (int i = 0; i < n; i++) {
        i64 res = i64(n - i) * a[i] + pre;
        if (res < aff) {
            aff = res;
            p = i;
        }
        pre += a[i];
    }

    std::cout << p + 1 << "\n";
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