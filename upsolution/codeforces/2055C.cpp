#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector a(n, vector<ll>(m));
    for (int i{}; i < n; i++) {
        for (int j{}; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int i{}, j{};
    while (i + j < n + m - 1) {
        ll res{};
        if (i + j == n + m - 2 or s[i + j] == 'D') {
            for (int y = 0; y < m; y++) {
                res -= a[i][y];
            }
            a[i][j] = res;
            i++;
        } else {
            for (int x = 0; x < n; x++) {
                res -= a[x][j];
            }
            a[i][j] = res;
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m - 1];
        }
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