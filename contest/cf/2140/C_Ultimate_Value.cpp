#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += a[i];
        } else {
            sum -= a[i];
        }
    }

    vector<i64> f(n), g(n);
    for (int i = 0; i < n; i++) {
        f[i] = 2ll * a[i] + i;
        g[i] = 2ll * a[i] - i;

        // cerr << f[i] << " " << g[i] << endl;
    }
    i64 fy = -inf;
    for (int i = 1; i < n; i += 2) {
        fy = max(fy, f[i]);
    }
    i64 fx = inf;
    for (int i = 0; i < n; i += 2) {
        fx = min(fx, f[i]);
    }
    i64 ans1 = sum - fx + fy;

    i64 gy = -inf;
    for (int i = 1; i < n; i += 2) {
        gy = max(gy, g[i]);
    }
    i64 gx = inf;
    for (int i = 0; i < n; i += 2) {
        gx = min(gx, g[i]);
    }
    i64 ans3 = sum - gx + gy;

    i64 ans2 = sum;
    if (n % 2 == 1) {
        ans2 += n - 1;
    } else if (n > 2) {
        ans2 += n - 2;
    }

    i64 ans = max({ans1, ans2, ans3});

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