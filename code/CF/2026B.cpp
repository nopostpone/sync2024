#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 能 O(n^2) 就别想着线性做了

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    ll res = 1e18;
    
    auto work = [&]() {
        const int m = a.size();
        ll now = 0;
        for (int i = 1; i < m; i += 2) {
            now = max(now, a[i] - a[i - 1]);
        }
        return now;
    };

    if (n % 2 == 0) {
        res = work();
    } else {
        for (int i = 0; i < n; i++) {
            ll x = a[i];
            a.erase(a.begin() + i);
            res = min(res, work());
            a.insert(a.begin() + i, x);
        }
    }

    cout << res << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}