#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        ranges::sort(a[i]);
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    ranges::sort(p, [&](int u, int v) {
        return a[u][0] < a[v][0];
    });

    int mx = a[p.back()][0];

    bool ok = true;
    for (int j = 1; j < m and ok; j++) {
        for (int i = 0; i < n; i++) {
            if (a[p[i]][j] < mx) {
                ok = false;
            }
            mx = a[p[i]][j];
        }
    }

    if (ok) {
        for (auto x : p) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}