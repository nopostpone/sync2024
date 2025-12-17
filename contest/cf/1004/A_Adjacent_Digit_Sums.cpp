#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int x, y;
    cin >> x >> y;

    bool ok = true;
    if (y == x) {
        ok = false;
    } else if (y > x + 1) {
        ok = false;
    } else if (y < x) {
        int u = x - y + 1;
        if (u % 9) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}