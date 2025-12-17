#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using pii = pair<int, int>;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    pii u, v, w;

    if (d - c < b - a) {
        u = {a, d - 1};
        v = {b, d};
        w = {b - 1, d};
    } else {
        u = {a, c};
        v = {a + 1, d};
        w = {a, c + 1};
    }
    for (auto [x, y] : {u, v, w}) {
        cout << x << " " << y << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}