#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    u64 k;
    cin >> k;

    if (k == 1) {
        cout << 2 << "\n";
        return;
    }

    u64 lo = 6, hi = 3e18;
    while (lo < hi) {
        u64 m = (lo + hi) / 2;
        int u = 64 - __builtin_clzll(m) - 2;

        // cerr << m << " " << u << endl;

        if (m >= (k + u) * 2) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << lo << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    // for (int i = 0; i < (int)1e5; i++) {
    //     solve();
    // }

    return 0;
}