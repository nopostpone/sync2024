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

    ll A1 = 0, A2 = 0, A3 = 0;
    for (int i = 0; i < n; i++) {
        A1 += (a[i] % 3 == 1);
        A2 += (a[i] % 3 == 2);
        A3 += (a[i] / 3);
    }

    ll res = 0;
    if (2ll * A2 + A1 <= A3) {
        ll s = A1 + 2ll * A2 + 3ll * A3;
        res = (s / 4 + (s % 4) / 2 + (s % 2));
    } else if (A1 > A3) {
        res = A3;
        A1 -= A3;
        res += 1ll * A1 + A2;
    } else {
        res = A1;
        A3 -= A1;
        res += A3 + (A2 - A3 / 2);
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