#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1000000000));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> ndp = vector<vector<int>>(n + 1, vector<int>(n + 1, 1000000000));
            for (int j = 0; j <= i; j++) {
                if (dp[j][i - j] == 1000000000) continue;
                int val = dp[j][i - j];
                int cnt0 = i - j;
                int cnt1 = j;

                int add0 = 0;
                for (int k = 0; k < i; k++) {
                    if (p[k] > p[i]) {
                        add0++;
                    }
                }
                add0 -= cnt1;
                ndp[j][i - j + 1] = min(ndp[j][i - j + 1], val + add0 + cnt1);

                int add1 = 0;
                for (int k = 0; k < i; k++) {
                    if (p[k] < p[i]) {
                        add1++;
                    }
                }
                add1 -= cnt0;
                ndp[j + 1][i - j] = min(ndp[j + 1][i - j], val + add1);
            }
            dp = ndp;
        }

        int ans = 1000000000;
        for (int j = 0; j <= n; j++) {
            ans = min(ans, dp[j][n - j]);
        }
        cout << ans << '\n';
    }
    return 0;
}