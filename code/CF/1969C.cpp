#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    if (n == 1) {
        cout << a[1] << endl;
        return;
    }
    if (k == 0) {
        ll res = 0;
        for (auto x : a) {
            res += x;
        }
        cout << res << endl;
        return;
    }

    vector dp(n + 1, vector<ll>(k + 1, 4e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j] + a[i];
            int mn = a[i];
            for (int t = i - 1; t >= 0 and t >= i - j - 1; t--) {
                mn = min(mn, a[t + 1]);
                dp[i][j] = min<ll>(dp[i][j], dp[t][j - (i - t - 1)] + 1ll * (i - t) * mn);
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}