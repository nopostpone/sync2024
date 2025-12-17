#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll S = (k + n + k - 1) * n / 2;

    auto check = [&](ll x) {
        ll A = (k + k + x - 1) * x / 2;
        return A < S - A;
    };

    int lo = 0, hi = n;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (check(m)) {
            lo = m + 1;
        } else {
            hi = m;
        }
    }
    auto f = [&](int x) -> ll {
        ll A = (k + k + 1ll * x - 1) * 1ll * x / 2;
        return A;
    };

    cout << std::min<ll>(2 * f(lo) - S, S - 2 * f(lo - 1)) << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}