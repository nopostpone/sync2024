#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(18);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    vector<double> dp(n + 1, 1e18);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j <= n; j++) {
            sum += dp[j];
            double res = (double)a[j] + sum / (j - i + 1);
            double coef = double(j - i + 1) / (j - i);

            dp[i] = min(dp[i], res * coef);
        }
    }

    cout << dp[0] << "\n";

    return 0;
}

/*
2
10 24 100
*/