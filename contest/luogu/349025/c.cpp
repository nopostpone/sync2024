#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

int P;

constexpr int N = 18;
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

Mat f {};

void solve() {
    int a, b;
    std::cin >> a >> b >> P;

    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        f[0][i] = 10;
        f[9][i] = 0;
    }
    for (int i = 9; i < 18; i++) {
        f[0][i] = i - 8;
        f[9][i] = 1;
    }
    for (int i = 1; i < 9; i++) {
        f[i][i - 1] = 1;
    }
    for (int i = 10; i < 18; i++) {

    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}