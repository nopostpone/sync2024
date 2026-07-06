#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

std::string get(u32 x, int n) {
    if (x == 0) {
        return std::string(n, '0');
    }
    std::string s;

    std::vector<int> b;
    while (x) {
        b.push_back(x & 1);
        x >>= 1;
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        s += b[i % b.size()] + '0';
    }
    return s;
}

void solve() {
    u32 l, r;
    int n;
    std::cin >> l >> r >> n;

    int L = (int)std::bit_width(l);
    int R = (int)std::bit_width(r);

    std::string ans(n, '1');

    if (L == R) {
        int k = L - 1;
        u32 d = l ^ r;

        k = 31 - std::countl_zero(d);
        ans = get((l >> (k + 1)) << (k + 1), n);
    } else {
        u32 y = 1 << (R - 1);
        u32 x = std::max(l, u32(1 << (R - 2)));

        auto s1 = get(x, n);
        auto s2 = get(y, n);

        for (int i = 0; i < n; i++) {
            ans[i] = (s1[i] == '1' and s2[i] == '1') ? '1' : '0';
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
