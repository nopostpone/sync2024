#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 60;
int dp[N][N], g[N][N];

constexpr int inf = 1e9;

void solve() {
    array<i64, 2> x;
    cin >> x[0] >> x[1];
    if (x[1] < x[0]) {
        swap(x[0], x[1]);
    }

    array<int, 2> a{};
    for (int i = 0; i < 2; i++) {
        if (x[i]) {
            a[i] = __lg(x[i]);
        } else {
            a[i] = -1;
        }
    }
    const int dif = a[1] - a[0];

    i64 v = x[0] ^ (x[1] >> dif);
    int s = (v == 0 ? 0 : __lg(v) + 1);
    int t = s + dif;

    int ans = g[a[0] + 1][a[1] + 1];
    for (int i = 0; i + t <= a[1]; i++) {
        ans = min(ans, dp[s + i][t + i]);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 0; i < N; i++) {
        fill(dp[i], dp[i] + N, inf);
    }
    dp[0][0] = 0;

    for (int k = 1; k <= 30; k++) {
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (i >= k) {
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + (1 << k));
                }
                if (j >= k) {
                    dp[i][j] = min(dp[i][j], dp[i][j - k] + (1 << k));
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g[i][j] = inf;
            for (int x = i; x < N; x++) {
                for (int y = j; y < N; y++) {
                    g[i][j] = min(g[i][j], dp[x][y]);
                }
            }
        }
    }

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}