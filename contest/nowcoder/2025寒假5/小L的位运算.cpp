#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    string a, b, c;
    cin >> a >> b >> c;

    i64 ans = 0;
    if (2 * x < y) {
        for (int i = 0; i < n; i++) {
            if (c[i] == '1' and (a[i] == b[i])) {
                ans += x;
            } else if (c[i] == '0' and (a[i] != b[i])) {
                ans += x;
            }
        }
    } else {
        int t[2][2]{};
        for (int i = 0; i < n; i++) {
            int u = a[i] - '0';
            int v = b[i] - '0';
            if (c[i] == '1' and u == v) {
                t[u][v]++;
            } else if (c[i] == '0' and u != v) {
                t[u][v]++;
            }
        }
        int sum = 0;
        int mx = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                sum += t[i][j];
                mx = max(mx, t[i][j]);
            }
        }
        if (mx > sum - mx) {
            ans = 1ll * (sum - mx) * y + 1ll * (mx - sum + mx) * x;
        } else {
            ans = 1ll * (sum / 2) * y;
            if (sum % 2) {
                ans += x;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}