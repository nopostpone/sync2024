#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n * 2);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n; i < n * 2; i++)
        a[i] = a[i - n];

    vector<int> s(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++)
        s[i] = s[i - 1] + a[i - 1];

    vector dp(n * 2, vector<int>(n * 2, 1e9));
    for (int i = 0; i < n * 2; i++)
        dp[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < 2 * n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j + 1] - s[i]);
            }
        }
    }
    int Min = 1e9;
    for (int i = n; i < n * 2; i++) {
        Min = min(Min, dp[i - n][i - 1]);
    }

    dp.resize(2 * n, vector<int>(2 * n, -1e9));
    for (int i = 0; i < 2 * n; i++)
        dp[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < 2 * n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j + 1] - s[i]);
            }
        }
    }
    int Max = -1e9;
    for (int i = n; i < n * 2; i++) {
        Max = max(Max, dp[i - n][i - 1]);
    }

    cout << Min << endl
         << Max << endl;

    return 0;
}