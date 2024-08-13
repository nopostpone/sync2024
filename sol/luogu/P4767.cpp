#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector w(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k <= j; k++) {
                w[i][j] += abs(a[k] - a[(i + j) / 2]);
            }
        }
    }

    vector dp(n, vector<int>(m + 1, 1e9));
    for (int i = 0; i < m; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < i; k++) {
                cerr << i << " " << j << " " << k << endl;
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + w[k + 1][i]);
            }
        }
    }
    cout << dp[n - 1][m];

    return 0;
}