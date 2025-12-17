#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector dp(n + 1, vector<ll>(2));

    dp[1][1] = a[0];
    dp[1][0] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max<ll>(dp[i - 1][0], dp[i - 1][1] + 2 * a[i - 1]);
        dp[i][1] = max<ll>(dp[i - 1][1], dp[i - 1][0] + a[i - 1]);
    }
    cout << max(dp[n][1], dp[n][0]);
    
    return 0;
}
