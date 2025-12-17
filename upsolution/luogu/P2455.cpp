#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr double eps = 1e-12;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);

    int n;
    cin >> n;

    vector a(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        int r = cur;
        for (int j = cur; j < n; j++) {
            if (abs(a[j][i]) > abs(a[r][i])) {
                r = j;
            }
        }
        swap(a[r], a[cur]);
        if (abs(a[cur][i]) < eps) {
            continue;
        }

        for (int j = n; j >= i; j--) {
            a[cur][j] /= a[cur][i];
        }
        for (int j = 0; j < n; j++) {
            if (j == cur) {
                continue;
            }
            for (int k = n; k >= i; k--) {
                a[j][k] -= a[j][i] * a[cur][k];
            }
        }

        cur++;
    }
    if (cur < n) {
        bool ok = true;
        for (; cur < n; cur++) {
            if (abs(a[cur][n]) > eps) {
                ok = false;
            }
        }
        cout << (ok ? 0 : -1) << "\n";
        return 0;
    }

    vector<double> ans(n);
    ans[n - 1] = a[n - 1][n];
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            ans[i] -= (ans[j] * a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << "=" << ans[i] << "\n";
    }

    

    return 0;
}