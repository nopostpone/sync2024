#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int x = a[i];
            int y = a[j];

            ans += (x + y > a[n - 1]);
            int u = max(y, a[n - 1] - x - y + 1);
            int v = x + y - 1;
            // cerr << i << " " << j << " " << u << " " << v << endl;
            if (u > v) {
                continue;
            }

            int l = lower_bound(a.begin() + j + 1, a.end() - 1, u) - a.begin();
            int r = upper_bound(a.begin() + j + 1, a.end() - 1, v) - a.begin();
            // cerr << l << " " << r << endl;
            if (r >= l) {
                ans += r - l;
            }
        }
    }
    cout << ans << "\n";

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