#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int x, k;
    cin >> x >> k;

    if (x == 1) {
        for (int i = 0; i < k - 1; i++) {
            x = x * 10 + x;
        }
        bool ok = x != 1;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
        return;
    }

    bool ok = true;
    if (k > 1) {
        ok = false;
    } else {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                ok = false;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
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