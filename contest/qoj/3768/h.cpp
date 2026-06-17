#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

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

void solve() {
    std::string ox;
    std::cin >> ox;

    int p = ox.find('.');

    u64 x = stoull(ox.substr(0, p)) * 100 + stoull(ox.substr(p + 1));

    u64 ans = 4 * x - 300;

    std::string s = std::to_string(ans % 100);
    if (s.size() == 1) {
        s = '0' + s;
    }

    std::cout << (ans / 100) << '.' << s << "\n";
}

int main() {
    int t;
    std::cin >> t;

    std::cout << std::fixed << std::setprecision(2);

    while (t--) {
        solve();
    }
}