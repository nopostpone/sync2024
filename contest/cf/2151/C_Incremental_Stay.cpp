#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    vector<array<int, 2>> b(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        b[i][i & 1] = a[i];
        b[i][(i + 1) & 1] = -a[i];
    }
    vector<array<i64, 2>> pre(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2; j++) {
            pre[i + 1][j] = pre[i][j] + b[i][j];
        }
    }

    i64 ans = 0;
    for (int k = 0; k < n; k++) {
        ans += a[2 * n - 1 - k] - a[k];
        int t = (k + 1) % 2;

        cout << ans + pre[2 * n - 1 - k][t] - pre[k + 1][t] << " \n"[k == n - 1];
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
