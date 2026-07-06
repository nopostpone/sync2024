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

    std::vector<int> a(n);
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        c[a[i]]++;
    }

    std::vector<int> seq;
    for (int i = 0; i < n; i++) {
        if (c[i] != 0) {
            seq.push_back(c[i]);
        }
    }
    rgs::sort(seq);

    int m = seq.size();

    std::vector<int> pre(m + 1);
    for (int i = 0; i < m; i++) {
        pre[i + 1] = pre[i] + seq[i];
    }

    std::unordered_set<int> ans;
    for (int t = 0; t < seq.back(); t++) {
        int i = std::upper_bound(seq.begin(), seq.end(), t) - seq.begin();
        int cnt = m - i;
        int len = n - pre[i] - cnt * t;
        if (k >= len and (k - len) % cnt == 0) {
            ans.insert(i);
        }
    }

    std::cout << ans.size() << "\n";

    // int pre = 0;

    // {
    //     int cnt = m;
    //     int len = n;
    //     if ((k - len) % cnt == 0) {
    //         std::cerr << cnt << "\n";
    //         ans++;
    //     }
    // }
    // for (int i = 0; i < m - 1; i++) {
    //     pre += seq[i];
    //     if (seq[i] == seq[i + 1]) {
    //         continue;
    //     }
    //     int cnt = m - i - 1;
    //     int len = n - pre - cnt * seq[i];
        
    //     if ((k - len) % cnt == 0) {
    //         // std::cerr << cnt << "\n";
    //         ans++;
    //     }
    // }
    // std::cout << ans << "\n";

    // std::cerr << 1;
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