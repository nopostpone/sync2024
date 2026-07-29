#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int P = 998244353;

constexpr int N = 128;
using Mat = std::array<std::array<u64, N>, N>;
constexpr Mat operator*(const Mat &a, const Mat &b) {
    Mat c {};
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                c[i][j] += a[i][k] * b[k][j];
                if ((k & 15) == 15) {
                    c[i][j] %= P;
                }
            }
        }
    }
    return c;
}
constexpr Mat power(Mat a, u64 b) {
    Mat res {};
    for (int i = 0; i < N; i++) {
        res[i][i] = 1;
    }
    for (; b != 0; b /= 2, a = a * a) {
        if (b & 1) {
            res = res * a;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    if (n == 1) {
        u64 a = 2;
        u64 ans = 3;
        for (int b = m - 1; b; b /= 2, a = a * a % P) {
            if (b & 1) {
                ans = ans * a % P;
            }
        }
        std::cout << ans << "\n";
        return 0;
    }
    
    auto decode = [&](int s, int x, int y) {
        std::vector<int> a(n);
        a[0] = x;
        a[1] = y;
        for (int i = 0; i < n - 2; i++) {
            a[i + 2] = (s >> i & 1) ? a[i] : (3 - a[i] - a[i + 1]);
        }
        return a;
    };
    auto check = [&](const auto &a, const auto &b) {
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                return false;
            }
        }
        return true;
    };

    Mat dp {};

    constexpr std::pair<int, int> perm[] {{0, 1}, {0, 2}, {1, 2}};
    for (int s = 0; s < 1 << (n - 2); s++) {
        auto a = decode(s, 0, 1);
        for (int t = 0; t < 1 << (n - 2); t++) {
            for (auto [x, y] : perm) {
                dp[s][t] += check(a, decode(t, x, y));
                dp[s][t] += check(a, decode(t, y, x));
            }
        }
    }

    dp = power(dp, m - 1);
    u64 ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += dp[i][j];
            if (ans >= P) {
                ans -= P;
            }
        }
    }

    std::cout << 6 * ans % P << "\n";
}
