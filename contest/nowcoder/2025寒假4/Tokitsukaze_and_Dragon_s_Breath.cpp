#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<i64> b(n + m), c(n + m);

    for (int i = -m; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = j - i;
            if (x < 0 or x >= m) {
                continue;
            }
            b[i + m] += a[j][x];
        }
    }
    for (int i = 0; i < n + m; i++) {
        for (int j = 0; j < n; j++) {
            int x = i - j;
            if (x < 0 or x >= m) {
                continue;
            }
            c[i] += a[j][x];
        }
    }

    i64 ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            i64 tem = -a[i][j];
            tem += b[i - j + m];
            tem += c[i + j];
            ans = max(ans, tem);
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}