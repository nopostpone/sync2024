#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n, k;
    std::cin >> n >> k;

    if (k == n - 1) {
        std::cout << -1 << "\n";
        return;
    }

    int m = n - k;
    int t = (n - m + 2) / 2;

    std::string s(n, '?');
    for (int i = 0; i < t; i++) {
        s[i] = '0';
    }
    for (int i = t; i < 2 * t; i++) {
        s[i] = '1';
    }
    int b = 2 * t;
    if (k % 2 == 1) {
        s[b] = '1';
        b++;
    }
    for (int i = b, j = 0; i < n; i++, j = 1 - j) {
        s[i] = '0' + j;
    }
    std::cout << s << "\n";
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