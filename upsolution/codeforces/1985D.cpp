#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string a;
    a.resize(m);
    bool ok = 0;
    int x, y1, y2;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[j];
        }
        if (!ok) {
            if (a.find('#') != string::npos) {
                x = a.find('#') + 1;
                y1 = i;
                ok = 1;
            }
        } else {
            if (a.find('#') == string::npos) {
                y2 = i - 1;
                ok = 0;
            }
        }
    }
    if (ok) {
        y2 = n;
    }
    cout << int(y1 + y2 >> 1) << ' ' << x << "\n";
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}