#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll l, r, g;
    cin >> l >> r >> g;

    l += g - 1;
    l /= g;
    r /= g;

    ll len = r - l;
    while (len >= 0) {
        for (ll i = l; i <= r - len; i++) {
            if (__gcd(i, i + len) == 1) {
                cout << i * g << " " << (i + len) * g << "\n";
                return;
            }
        }
        len--;
    }
    cout << -1 << " " << -1 << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}