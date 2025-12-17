#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector b(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++) {
        bool exi = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '0') {
                exi = true;
            }
            if (a[i][j] == '1' and exi) {
                b[i][j] = 0;
            }
        }
    }
    
    vector c(n, vector<int>(m, 1));
    for (int j = 0; j < m; j++) {
        bool exi = false;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '0') {
                exi = true;
            }
            if (a[i][j] == '1' and exi) {
                c[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] |= c[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1' and not b[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}