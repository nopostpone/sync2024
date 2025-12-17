#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    array<i64, 2> dp {};
    for (int i = 0; i < n; i++) {
        // cerr << b[i] << " " << dp[0] << "\n";
        array<i64, 4> c = {dp[0] - a[i], dp[1] - a[i], b[i] - dp[0], b[i] - dp[1]};
        
        // cerr << b[i] << " " << dp[0] << "\n";
        // cerr << b[i] - dp[0] << "\n";

        // for (auto x : c) {
        //     cerr << x << " ";
        // }
        // cerr << "\n";
        ranges::sort(c);
        dp[0] = c[0];
        dp[1] = c[3];

        // cerr << dp[0] << " " << dp[1] << "\n";
    }
    cout << dp[1] << "\n";
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
