#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, x, y;

void solve() {
    cin >> n >> x >> y;
    bool okx = 0, oky = 0;
    if ((y) & 1)
        okx = 1;
    for (int i = 1; i < y; i++) {
        if (okx)
            cout << 1 << ' ';
        else
            cout << -1 << ' ';
        okx ^= 1;
    }
    for (int i = y; i <= x; i++) {
        cout << 1 << ' ';
    }
    for (int i = x + 1; i <= n; i++) {
        if (oky)
            cout << 1 << ' ';
        else
            cout << -1 << ' ';
        oky ^= 1;
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}