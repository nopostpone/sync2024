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

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<int> f(n + 1);
    for (int i = 1; i < n; i++) {
        f[i] = (a[i] != a[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
        // cerr << f[i] << " \n"[i == n];
    }

    for (int _ = 0; _ < q; _++) {
        int l, r;
        cin >> l >> r;
        l--;

        if ((r - l) % 3 != 0 or (pre[r] - pre[l]) % 3 != 0) {
            cout << -1 << "\n";
            continue;
        }
        int ans = (r - l) / 3;
        if (f[r - 1] - f[l] == r - l - 1) {
            ans++;
        }
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