#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int P = 1'000'000'007;

constexpr int N = 102;

using Mat = array<array<int, N>, N>;

constexpr int norm(int x) {
    if (x >= P) {
        x -= P;
    }
    if (x < 0) {
        x += P;
    }
    return x;
}

constexpr Mat operator*(const Mat &a, const Mat &b) {
    Mat c {};
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                c[i][j] += 1ll * a[i][k] * b[k][j] % P;
                c[i][j] = norm(c[i][j]);
            }
        }
    }
    return c;
}
constexpr Mat power(Mat a, i64 b) {
    Mat res {};
    for (int i = 0; i < N; i++) {
        res[i][i] = 1;
    }
    for (; b; b /= 2, a = a * a) {
        if (b & 1) {
            res = res * a;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> t(k - 1);
    for (int i = 0; i < k - 1; i++) {
        cin >> t[i];
    }

    vector<int> dp(101);
    for (int i = 1; i <= 100; i++) {
        dp[i] = norm(dp[i - 1] + 1);

        for (auto x : t) {
            if (i - 1 - x >= 0) {
                dp[i] += dp[i - 1] - dp[i - 1 - x] + 1;
                dp[i] = norm(dp[i]);
            }
        }
    }

    if (n <= 100) {
        cout << dp[n] << "\n";
        return 0;
    }

    vector<int> init(N);
    for (int i = 0; i < N - 1; i++) {
        init[i] = dp[N - 2 - i];
    }
    init[N - 1] = 1;

    Mat f {};
    f[0][0] = f[0][N - 1] = k;
    for (auto x : t) {
        f[0][x]--;
        f[0][x] = norm(f[0][x]);
    }
    for (int i = 1; i < N - 1; i++) {
        f[i][i - 1] = 1;
    }
    f[N - 1][N - 1] = 1;

    f = power(f, n - 100);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += 1ll * f[0][i] * init[i] % P;
        ans = norm(ans);
    }

    cout << ans << "\n";

    return 0;
}

/*
114514 5
28 26 70 27
*/
