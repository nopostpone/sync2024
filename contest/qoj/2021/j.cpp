#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector a(n, vector(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector pre(n + 1, vector<i64>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] + a[i][j] - pre[i][j];
        }
    }

    vector<i64> r(n), c(m);
    for (int i = 0; i < n; i++) {
        r[i] = pre[i + 1][m];
    }
    for (int i = 0; i < m; i++) {
        c[i] = pre[n][i + 1];
    }

    vector<i64> f(n + m + 1, inf);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            f[i + j] = min(f[i + j], pre[i][j]);
        }
    }
    for (int i = n + m - 1; i >= 0; i--) {
        f[i] = min(f[i], f[i + 1]);
    }

    for (int _ = 0; _ < q; _++) {
        i64 s;
        cin >> s;

        int p1 = upper_bound(r.begin(), r.end(), s) - r.begin();
        int p2 = upper_bound(c.begin(), c.end(), s) - c.begin();

        cout << (n - p1 == m - p2 and f[n + m - (n - p1)] > s ? "Putata" : "Budada") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}