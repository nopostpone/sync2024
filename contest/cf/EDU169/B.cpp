#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    if (l > L) {
        swap(l, L);
        swap(r, R);
    }

    int res = 0;
    if (L > r) {
        res = 1;
    } else if (L != l) {
        if (R == r) {
            res = r - L + 1;
        } else {
            res = min(R, r) - L + 2;
        }
    } else {
        if (R == r) {
            res = r - L;
        } else {
            res = min(R, r) - L + 1;
        }
    }
    cout << res << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}