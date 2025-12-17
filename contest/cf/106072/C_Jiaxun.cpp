#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    int f[7];
    for (int i = 0; i < 7; i++) {
        cin >> f[i];
    }

    auto check = [&](int x) {
        int c[3] {};
        c[0] = f[0];
        c[1] = f[1];
        c[2] = f[3];

        int d[3] {};
        for (int i = 0; i < 3; i++) {
            d[i] = max(0, x - c[i]);
        }

        return n - c[0] - c[1] - c[2] >= d[0] + d[1] + d[2] and
            f[2] + f[4] + f[6] >= d[0] and
            f[2] + f[5] + f[6] >= d[1] and
            f[4] + f[5] + f[6] >= d[2];
    };

    int lo = -1, hi = n / 3;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    cout << lo << "\n";
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