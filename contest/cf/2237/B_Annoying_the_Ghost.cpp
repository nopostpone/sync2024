#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

using std::cerr, std::endl;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int ans = 0;
    std::vector<int> p(n);
    std::vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        bool match = false;
        for (int j = 0; j < n; j++) {
            if (not vis[j] and b[j] >= a[i]) {
                p[i] = j;
                vis[j] = true;
                match = true;
                break;
            }
        }
        if (not match) {
            std::cout << -1 << "\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                ans++;
            }
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
