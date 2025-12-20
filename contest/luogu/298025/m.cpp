#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> fac;

    int d = 1;
    for (; 1ll * d * d <= n; d++) {
        if (n % d == 0) {
            fac.push_back(d);
        }
    }
    if (d * d == n) {
        d--;
    }
    for (; d >= 1; d--) {
        if (n % d == 0) {
            fac.push_back(n / d);
        }
    }

    i64 ans = 1;
    for (int i = 0; i + 1 < fac.size(); i++) {
        ans += (fac[i + 1] - fac[i]) * 1ll * (n / fac[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}