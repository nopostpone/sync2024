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

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector f(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i + 1][j + 1] = f[i + 1][j] + f[i][j + 1] - f[i][j] + (s[i][j] == 'L');
        }
    }

    auto get = [&](int x1, int y1, int x2, int y2) {
        return f[x2][y2] - f[x1][y2] - f[x2][y1] + f[x1][y1];
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != 'H') {
                continue;
            }

            bool ok = false;
            {
                int hi = min(m, j + 6);
                int lo = max(0, j - 5);

                if (get(i, j, i + 1, hi) >= 2 or get(i, lo, i + 1, j) >= 2) {
                    ok = true;
                }
            }
            {
                int hi = min(n, i + 6);
                int lo = max(0, i - 5);
                
                if (get(i, j, hi, j + 1) >= 2 or get(lo, j, i, j + 1) >= 2) {
                    ok = true;
                }
            }
            ans += ok;
        }
    }
    cout << ans << "\n";

    return 0;
}