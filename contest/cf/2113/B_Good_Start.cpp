#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int w, h, a, b;
    cin >> w >> h >> a >> b;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    // cerr << dx << " " << dy << " " << a << " " << b << endl;

    if (dx >= a and dx % a == 0) {
        // cerr << 1 << endl;
        cout << "Yes\n";
    } else if (dy >= b and dy % b == 0) {
        // cerr << 2 << endl;
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}