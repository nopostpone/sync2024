#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n;
    char c;
    std::cin >> n >> c;

    std::string s;
    std::cin >> s;

    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - i - 1]) {

        } else {
            ans += 2 - (s[i] == c) - (s[n - i - 1] == c);
        }
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