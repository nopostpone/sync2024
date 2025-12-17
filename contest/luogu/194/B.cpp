#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    int c;
    for (c = 1; c <= 100000; c++) {
        if (z * c == x and c * w == y) {
            cout << c;
            return;
        }
    }
    cout << -1;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}