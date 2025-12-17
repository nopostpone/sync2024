#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> f(n + 1);
    vector<int> g1(n + 1), g2(n + 1);
    for (int i = 0; i < n; i++) {
        int cnt = __builtin_popcount(a[i]);
        int l = __lg(a[i]);

        g2[i + 1] = g2[i];
        g1[i + 1] = g1[i];

        if (cnt == 2 and a[i] % 2 == 1) {
            g1[i + 1]++;
        } else if (cnt >= 2) {
            g2[i + 1]++;
        }

        f[i + 1] = f[i] + l;
    }
    
    for (int _ = 0; _ < q; _++) {
        int l, r;
        cin >> l >> r;
        l--;

        int ans = f[r] - f[l];
        // cerr << f[r] - f[l] << " " << (g1[r] - g1[l]) << " " << g2[r] - g2[l] << endl;
        ans += (g1[r] - g1[l]) / 2;
        ans += g2[r] - g2[l];
        cout << ans << "\n";
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