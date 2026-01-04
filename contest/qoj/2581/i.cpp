#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void chmax(auto &a, auto b) {
    if (b > a) {
        a = b;
    }
}
constexpr double inf = 1e13;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 6>> info(n);
    for (auto &[a, b, c, d, e, op] : info) {
        cin >> a >> b >> c >> d >> e >> op;
    }

    reverse(info.begin(), info.end());

    vector<array<double, 4>> dp(m + 1);
    for (auto [a, b, c, d, e, op] : info) {
        double p = 0.01 * op;
        double q = 1 - p;

        vector<array<double, 4>> ndp(m + 1);
        for (auto &arr : ndp) {
            arr.fill(-inf);
        }

        for (int j = 0; j + b <= m; j++) {
            chmax(ndp[j + b][0], a + p * dp[j][1] + (1 - p) * dp[j][2]);
            chmax(ndp[j + b][1], a + p * dp[j][1] + (1 - p) * dp[j][3]);
            chmax(ndp[j + b][2], a + p * dp[j][3] + (1 - p) * dp[j][2]);
            chmax(ndp[j + b][3], a + dp[j][3]);
        }
        for (int j = 0; j + d + e <= m; j++) {
            chmax(ndp[j + d + e][3], c + dp[j][0]);
        }
        for (int j = 0; j + d <= m; j++) {
            chmax(ndp[j + d][0], c + p * dp[j][1] + (1 - p) * dp[j][2]);
            chmax(ndp[j + d][1], c + p * dp[j][1] + (1 - p) * dp[j][3]);
            chmax(ndp[j + d][2], c + p * dp[j][3] + (1 - p) * dp[j][2]);
        }

        dp = move(ndp);
    }

    double ans = -inf;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, dp[i][0]);
    }
    if (ans < 0) {
        ans = -1;
    }

    cout << fixed << setprecision(10) << ans << "\n";    
}

/*
6 20
1 2 3 10 1 69
5 1 12 2 2 23
0 4 2 3 5 41
6 1 6 9 0 84
1 1 14 9 5 98
3 2 13 2 4 43

3 10
10 4 30 8 1 0
10 4 20 5 1 100
10 6 5 2 1 50

10 200
0 0 11 25 4 0
0 0 18 15 8 68
0 0 38 6 8 76
0 0 3 7 10 18
0 0 7 19 10 81
1 5 16 21 1 50
11 0 15 9 10 100
3 10 47 5 6 7
14 3 23 18 10 84
2 2 4 3 8 100
*/
