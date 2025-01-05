#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(m + 1);
    dp[0] = 1;
    for (auto x : a) {
        auto odp(dp);
        for (int i = m; i >= x; i--) {
            dp[i] += odp[i - x];
        }
    }

    cout << dp[m] << "\n";

    return 0;
}