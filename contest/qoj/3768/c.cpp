#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    const int k = n / 3;

    for (int i = 0; i < n / 3 * 3; i++) {
        std::cout << (i / 3) + 1 + (i % 3) * k << " ";
    }
    int x = n / 3 * 3;
    for (int i = x; i < n; i++) {
        std::cout << i + 1 << " ";
    }


    std::cout << "\n";
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}