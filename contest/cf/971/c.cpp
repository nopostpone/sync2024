#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int X = 0, Y = 0;
    if (x != 0) {
        X = (x - 1) / k + 1;
    }
    if (y != 0) {
        Y = (y - 1) / k + 1;
    }

    int res = 0;
    if (X > Y) {
        res = 2 * X - 1;
    } else {
        res = 2 * Y;
    }
    cout << res << endl;
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