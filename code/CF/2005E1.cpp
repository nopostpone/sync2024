#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l, n, m;
    cin >> l >> n >> m;

    vector<int> a(l);
    for (int i = 0; i < l; i++) {
        cin >> a[i];
    }

    vector b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    set<int> s;
    for (int i = 0; i < l; i++) {
        if (s.contains(a[i])) {
            l = i;
            break;
        }
        s.insert(a[i]);
    }

    vector dp(l, vector(n, vector<bool>(m)));
    for (int i = n - 1; ~i; i--) {
        for (int j = m - 1; ~j; j--) {
            for (int k = 0; k < l; k++) {

                if (i < n - 1 and dp[k][i + 1][j]) {
                    dp[k][i][j] = true;
                } else if (j < m - 1 and dp[k][i][j + 1]) {
                    dp[k][i][j] = true;
                } else if (a[k] == b[i][j]) {
                    if (i < n - 1 and j < m - 1 and k < l - 1) {
                        dp[k][i][j] = not dp[k + 1][i + 1][j + 1];
                    } else {
                        dp[k][i][j] = true;
                    }
                }

            }
        }
    }

    cout << (dp[0][0][0] ? "T" : "N") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}