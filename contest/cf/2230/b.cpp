#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();

    int res = rgs::count(s, '1') + rgs::count(s, '3');
    int ans = res;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' or s[i] == '3') {
            res--;
        }
        if (s[i] == '2') {
            res++;
        }

        ans = std::max(ans, res);
    }
    ans = n - ans;
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