#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using pii = pair<int, int>;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a * d == b * c) {
        if (a == b) {
            cout << 0 << "\n";
        } else {
            cout << 2 << "\n";
            cout << 1 << " " << a << "\n";
            cout << 2 << " " << c << "\n";
        }
    } else {
        
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