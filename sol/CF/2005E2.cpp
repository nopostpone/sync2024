#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l, n, m;
    cin >> l >> n >> m;

    map<int, int> f;

    vector<int> a(l);
    for (int i = 0; i < l; i++) {
        cin >> a[i];
        if (not f.contains(a[i])) {
            f[a[i]] = i;
        }
        a[i] = f[a[i]];
    }

    vector r(l, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (f.contains(x)) {
                r[f[x]][i] = j;
            }
        }
    }

    bool res = 0;
    vector g(l, vector<bool>(n));
    for (int i = l - 1; ~i; i--) {
        int t = 0;
        for (int j = n - 1; ~j; j--) {
            if (r[a[i]][j] >= t) {
                g[i][j] = true;
                if (i == 0) {
                    res = true;
                }
            }
            if (i == l - 1) {
                continue;
            }
            if (g[i + 1][j]) {
                t = max(t, r[a[i + 1]][j]);
            }
        }
    }

    cout << (res ? "T" : "N") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}