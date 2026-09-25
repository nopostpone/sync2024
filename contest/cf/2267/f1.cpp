#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> seq;
    seq.push_back(rgs::max(a) - rgs::min(a));
    
    while (seq.back() != 0) {
        std::vector<int> na;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                na.push_back(a[i] xor a[j]);
            }
        }
        rgs::sort(na);
        na.resize(n);

        a = std::move(na);
        seq.push_back(rgs::max(a) - rgs::min(a));
    }

    for (int _ = 0; _ < q; _++) {
        int x;
        std::cin >> x;

        x = std::min((int)seq.size() - 1, x);
        std::cout << seq[x] << "\n";
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