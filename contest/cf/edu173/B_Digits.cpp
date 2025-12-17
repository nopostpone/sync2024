#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, d;
    cin >> n >> d;

    cout << 1 << " ";

    bool ok{};
    if (d % 3 == 0) {
        ok = true;
    } else {
        ok = (n >= 3);
    }
    if (ok) {
        cout << 3 << " ";
    }

    ok = (d == 5);
    if (ok) {
        cout << 5 << " ";
    }

    ok = (d == 7);
    if (n >= 3) {
        ok = true;
    }
    if (ok) {
        cout << 7 << " ";
    }

    ok = false;
    if (d == 9) {
        ok = true;
    } else if (n >= 6) {
        ok = true;
    } else if (n >= 3 and (d % 3 == 0)) {
        ok = true;
    }
    if (ok) {
        cout << 9 << " ";
    }

    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}

