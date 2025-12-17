#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;
    x /= 10;
    y *= 10;
    int z = 10000 - x - y;
    cout << x << ' ' << y << ' ' << z << endl;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}