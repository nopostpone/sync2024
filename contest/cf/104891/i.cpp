#include <bits/stdc++.h>
using namespace std;

constexpr void chmax(auto &x, auto y) {
    if (y > x) {
        x = y;
    }
}

void solve() {
    int a, b, m;
    cin >> a >> b >> m;

    vector<int> dp(m + 1);
    dp[0] = 2;

    int t1 = b;
    int v1 = b / a + 1;
    int t2 = (b + a - 1) / a * a;
    int v2 = (b + a - 1) / a + 1;

    for (int i = 0; i <= m; i++) {
        if (i + a <= m) {
            chmax(dp[i + a], dp[i] + 1);
        }
        if (i + t1 <= m) {
            chmax(dp[i + t1], dp[i] + v1);
        }
        if (i + t2 <= m) {
            chmax(dp[i + t2], dp[i] + v2);
        }
    }
    
    cout << 160 * ranges::max(dp) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
}

/*
6
50 100 0
40 10 50
10 40 50
1 1 1000000
60 200 960
60 185 905
*/