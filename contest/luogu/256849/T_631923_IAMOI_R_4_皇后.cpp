#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    i64 n, m, x[2], y[2];
    cin >> n >> m;

    for (int i = 0; i < 2; i++) {
        cin >> x[i] >> y[i];
    }

    if (x[0] == x[1] and y[0] == y[1]) {
        cout << 0 << "\n";
        return;
    }
    auto dx = abs(x[0] - x[1]);
    auto dy = abs(y[0] - y[1]);
    if (max(dx, dy) == 1) {
        cout << 1 << "\n";
        return;
    }

    if (x[0] != x[1] and y[0] != y[1]) {
        cout << 2 << "\n";
        return;
    }

    auto valid = [&](i64 x, i64 y) {
        return 0 < x and 0 < y and x <= n and y <= m;
    };
    int ans = 0;
    if (y[0] == y[1]) {
        swap(x, y);
        swap(n, m);
    }
    auto d = abs(y[0] - y[1]);
    // assert(d);
    if (d % 2 == 1) {
        if (valid(x[1] - d, y[1]) or valid(x[1] + d, y[1]) or
            valid(x[0] - d, y[0]) or valid(x[0] + d, y[0])) {
                ans = 2;
            } else {
                ans = 3;
            }
    } else {
        auto cy = min(y[0], y[1]) + d / 2;
        if (valid(x[0] - d / 2, cy) or valid(x[0] + d / 2, cy) or
            valid(x[1] - d, y[1]) or valid(x[1] + d, y[1]) or
            valid(x[0] - d, y[0]) or valid(x[0] + d, y[0])) {
            ans = 2;
        } else {
            ans = 3;
        }
    }
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}