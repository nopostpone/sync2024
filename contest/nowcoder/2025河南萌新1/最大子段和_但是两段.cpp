#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<i64> f(n + 1, -inf), g(n + 1, -inf);
    // f[0] = 0;
    i64 cur = 0;
    for (int i = 0; i < n; i++) {
        cur = max(cur + a[i], (i64)a[i]);
        f[i + 1] = max(cur, f[i]);
    }
    // g[n] = 0;
    cur = 0;
    for (int i = n; i > 0; i--) {
        cur = max(cur + a[i - 1], (i64)a[i - 1]);
        g[i - 1] = max(cur, g[i]);
    }

    i64 ans = -inf;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, f[i] + g[i]);
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