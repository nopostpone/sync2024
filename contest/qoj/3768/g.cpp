#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 998244353;

int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = i64(a) * a % P) {
        if (b & 1) {
            res = i64(res) * a % P;
        }
    }
    return res;
}

int main() {
    int x;
    std::cin >> x;

    int ans = x;
    if (x != 0) {
        ans = i64(ans) * power(10, x - 1) % P;
    }
    std::cout << ans << "\n";

    // for (int x = 1; x <= 10000; x *= 10) {

    //     i64 ans = 0;
    //     for (int i = 0; i < x; i++) {
    //         int j = i;
    //         while (j) {
    //             if ((j % 10) == 1) {
    //                 ans++;
    //             }
    //             j /= 10;
    //         }
    //     }
    //     std::cout << ans << '\n';
    // }
}