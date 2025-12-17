#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (s[i - 1][j - 1] == 'g');
        }
    }

    int sum = a[n][m];

    auto get = [&](int x, int y) {
        int xl = max(0, x - k + 1);
        int xr = min(n, x + k);
        int yl = max(0, y - k + 1);
        int yr = min(m, y + k);

        return a[xr][yr] - a[xl][yr] - a[xr][yl] + a[xl][yl];
    };

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                ans = max(ans, sum - get(i, j));
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