#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll query(int l, int r) {
    if (r - l <= 1) {
        return 0;
    }
    cout << "? " << l + 1 << " " << r << endl;
    ll x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    int x = query(0, n);
    if (x == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    string s{};
    for (int i = 1; i < n; i++) {
        ll y = query(i, n);
        if (y == x) {
            s += "1";
        } else {
            s += "0";
            if (y == 0) {
                s += string(x, '1');
                s.resize(n, '0');
                break;
            }
            x = y;
        }
    }
    cout << "! " << s << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}