#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    int mx = *max_element(a.begin(), a.end());

    int g{mx - a[0]};
    for (int i = 1; i < n; i++) {
        if (a[i] == mx) {
            continue;
        }
        g = std::gcd(g, mx - a[i]);
    }

    assert(g != 0);

    ll ans{};
    for (int i = 0; i < n; i++) {
        ans += (mx - a[i]) / g;
    }

    set<ll> s;
    for (auto i : a) {
        s.insert(i);
    }
    ll t{n};
    for (int i = 1; i < n; i++) {
        if (not s.contains(1ll * mx - i * g)) {
            t = i;
            break;
        }
    }

    cout << ans + t << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}