#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
T power(ll a, T b) {
    T res = 1;
    for (; b; b /= 2, a = 1LL * a * a) {
        if (res * a > 1e9) {
            return (T)1e9;
        }
        if (b % 2) {
            res = 1LL * res * a;
        }
    }
    return res;
}

mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n = rng() % 200000;
    n = max(n, 3);
    int m = n - (rng() % 26);
    m = max(m, 3);
    cout << n << " " << m << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}