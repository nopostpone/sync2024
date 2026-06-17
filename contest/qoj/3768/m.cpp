#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
    int n, m;
    std::cin >> n >> m;



    std::vector<int> p(n);
    // for (int i = 0; i < n - m; i++) {
    //     p[i] = i + m;
    // }
    // for (int i = n - m; i < n; i++) {
    //     p[i] = i - (n - m);
    // }
    for (int i = 0; i < n / 2; i++) {
        p[i] = i + (n - n / 2);
    }
    for (int i = n / 2; i < n; i++) {
        p[i] = i - n / 2;
    }

    i64 x = 0;
    for (int i = 0; i < n; i++) {
        x += std::min(std::abs(i - p[i]), m);
        std::cout << p[i] + 1 << " \n"[i == n - 1];
    }

    std::cerr << x << "\n";
}