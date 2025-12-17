#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using u128 = __uint128_t;

void solve() {
    ll n, m;
    cin >> n >> m;

    if (m == 1 or n <= m) {
        cout << 1 << "\n";
        return;
    }

    int ans = 1;
    ll now = m;
    ll mn = abs(now - n);
    int time = 1;

    while (now > 0 and now < n * m) {
        if ((u128)now * m > 1e18) {
            break;
        }
        time++;
        assert(time < 100);
        now *= m;
        ll t = abs(now - n);
        if (t < mn) {
            ans = time;
            mn = t;
        }
    }

    cout << ans << "\n"; 
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}