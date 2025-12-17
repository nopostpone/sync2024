#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    map<int, int> f;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        f[a]++;
    }

    bool ok = true;
    for (auto &[x, y] : f) {
        if (y == 1) {
            ok = false;
        } else if (y > 2) {
            f[x + 1] += y - 2;
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