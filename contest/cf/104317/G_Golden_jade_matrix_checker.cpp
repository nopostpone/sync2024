#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m, h, w;
    cin >> n >> m >> h >> w;

    vector a(n, vector<int>(m));
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
    if (pre[n][m] <= 0) {
        cout << "NO\n";
        return;
    }

    for (int i = h; i <= n; i++) {
        for (int j = w; j <= m; j++) {
            i64 sum = pre[i][j] - pre[i][j - w] - pre[i - h][j] + pre[i - h][j - w];
            if (sum >= 0) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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