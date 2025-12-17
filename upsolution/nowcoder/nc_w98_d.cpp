// https://ac.nowcoder.com/acm/contest/85598/D
// 区间 dp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + (s[i] == '1');
    
    vector dp(n + 1, vector<int>(n + 1));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;

            for (int k = i; k < j; k++) {
                int q0 = k - i + 1 - pre[k] + pre[i - 1];
                int q1 = pre[j] - pre[k];
                int t = std::abs(q0 - q1);

                if (l <= t and t <= r) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }
    }
    cout << dp[1][n];
    
    return 0;
}