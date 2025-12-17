#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128;

constexpr i64 inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<i64> f;
    for (int i = 0;; i++) {

        i64 x = (i64)i * i * i * i;
        if (x > 4e10) {
            break;
        }
        f.push_back(x);
    }

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<i64> dp(m + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; i - j >= 0 and j < 300; j++) {
            auto x = dp[i - j] + a[i] + f[j + 1];
            if (x <= dp[i + 1]) {
                dp[i + 1] = x;
            }
        }
    }

    cout << dp[m] << "\n";
}

/*
20 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/