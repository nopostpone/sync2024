#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int lo = 1, hi = 999;
    while (hi - lo > 1) {
        int x = lo + (hi - lo) / 3;
        int y = lo + (hi - lo) * 2 / 3;
        int res = query(x, y);
        if (res == x * y) {
            lo = y;
        } else if (res == x * (y + 1)) {
            lo = x;
            hi = y;
        } else {
            assert(res == (x + 1) * (y + 1));
            hi = x;
        }
    }
    cout << "! " << hi << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}