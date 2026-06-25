#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    i64 ans = i64(n) * (n + 1) / 2;

    std::array<int, 3> cnt {};
    int pre = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        pre += (s[i] - '0' + 1);
        ans -= cnt[pre % 3];
        cnt[pre % 3]++;
    }
    for (int l = 0, r; l < n; l = r) {
        r = l + 1;
        while (r < n and s[r] != s[r - 1]) {
            r++;
        }

        int len = r - l;
        if (len < 3) {
            continue;
        }
        if (len % 2 == 1) {
            int s = (len + 1) / 2 - 1;
            ans -= i64(s) * s;
        } else {
            int s = len / 2;
            ans -= i64(s) * (s - 1);
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