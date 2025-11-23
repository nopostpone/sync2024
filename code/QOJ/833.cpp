#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector s(n, vector<int>(m));
    int tot = 0;

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < m; j++) {
            s[i][j] = (t[j] == '.');
            tot += s[i][j];
        }
    }

    vector f(n, basic_string(m, false));
    f[0][0] = s[0][0];
    for (int i = 1; i < n; i++) {
        f[i][0] = f[i - 1][0] & s[i][0];
    }
    for (int i = 1; i < m; i++) {
        f[0][i] = f[0][i - 1] & s[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            f[i][j] = (f[i - 1][j] | f[i][j - 1]) & s[i][j];
        }
    }

    if (not f[n - 1][m - 1]) {
        cout << (i64)tot * (tot - 1) / 2 << "\n";
        return 0;
    }

    vector g(n, basic_string(m, false));
    g[n - 1][m - 1] = s[n - 1][m - 1];
    for (int i = n - 1; i >= 1; i--) {
        g[i - 1][m - 1] = g[i][m - 1] & s[i - 1][m - 1];
    }
    for (int i = m - 1; i >= 1; i--) {
        g[n - 1][i - 1] = g[n - 1][i] & s[n - 1][i - 1];
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = m - 1; j >= 1; j--) {
            g[i - 1][j - 1] = (g[i][j - 1] | g[i - 1][j]) & s[i - 1][j - 1];
        }
    }

    int t = n + m - 1;

    vector<pair<int, int>> pl(t), pr(t);
    vector visl(n, basic_string(m, false)), visr(visl);

    for (int i = t - 1, x = n - 1, y = m - 1; i >= 0; i--) {
        pl[i] = pair(x, y);

        if (y > 0 and (x == 0 or f[x][y - 1])) {
            y--;
        } else {
            x--;
        }
    }
    for (int i = t - 1, x = n - 1, y = m - 1; i >= 0; i--) {
        pr[i] = pair(x, y);
        visr[x][y] = true;

        if (x > 0 and (y == 0 or f[x - 1][y])) {
            x--;
        } else {
            y--;
        }
    }

    int sum = 0; // num of intersection points or pl and pr
    for (auto [x, y] : pl) {
        sum += visr[x][y];
        visl[x][y] = true;
    }

    // 1. intersection point + not intersection point
    // 2. intersection point + intersection point
    i64 ans = (i64)sum * (tot - sum) + (i64)sum * (sum - 1) / 2;

    for (auto [x, y] : pl) {
        if (visr[x][y]) {
            continue;
        }

        int u = x - 1, v = y + 1;
        while (not f[u][v] or not g[u][v]) {
            u--;
            v++;
        }

        for (int i = u, j = v; not visl[i][j];) {
            ans += visr[i][j];
            if (j and f[i][j - 1] and g[i][j - 1]) {
                j--;
            } else {
                i--;
            }
        }
        for (int i = u, j = v;;) {
            if (i + 1 < n and f[i + 1][j] and g[i + 1][j]) {
                i++;
            } else {
                j++;
            }

            if (visl[i][j]) {
                break;
            }
            ans += visr[i][j];
        }
    }

    cout << ans << "\n";

    return 0;
}