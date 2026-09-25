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

    std::map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[-x]++;
    }

    std::vector<int> b;

    int j = 0;

    while (b.size() < n) {
        j++;
        auto it = a.begin();
        int cnt = it->second;
        
        while (true) {
            int time = std::min(cnt, it->second);
            // std::cerr << time << "\n";

            it->second -= time;
            
            for (int i = 0; i < time; i++) {
                b.push_back(it->first);
            }
            if (it->second == 0) {
                it = a.erase(it);
            } else {
                it = std::next(it);
            }
            
            if (it == a.end()) {
                break;
            }
        }
        // std::cerr << "\t" << b.size() << "\n";
    }

    for (int i = 0; i < n; i++) {
        std::cout << -b[i] << " \n"[i == n - 1];
    }

    // std::vector<int> a(n);
    // for (int i = 0; i < n; i++) {
    //     std::cin >> a[i];
    // }

    // rgs::sort(a);
    
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