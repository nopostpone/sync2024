#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int l, r;
    cin >> l >> r;

    int n = r + 1;

    vector<int> a(n);
    auto work = [&](this auto &&self, int l, int r) {
        // cerr << l << " " << r << endl;
        if (r < 0) {
            return;
        }
        if (r == 0) {
            a[0] = 0;
            return;
        }
        int t = 1;
        while (t * 2 <= r) {
            t *= 2;
        }
        for (int i = t; i <= r; i++) {
            int j = 2 * t - 1 - i;

            // cerr << i << " " << j << endl;

            a[i] = j;
            a[j] = i;
        }

        self(0, 2 * t - 2 - r);
    };
    work(l, r);
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] | (i);
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
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