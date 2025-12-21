#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int f[][6] = {0, 1, 2, 2, 1, 0,
                        0, 2, 1, 1, 2, 0,
                        2, 0, 1, 1, 0, 2,
                        2, 1, 0, 0, 1, 2,
                        1, 2, 0, 0, 2, 1,
                        1, 0, 2, 2, 0, 1};

constexpr int g[][6] = {1, 2, 2, 0, 0, 1,
                        2, 1, 2, 0, 1, 0,
                        0, 1, 0, 2, 1, 2,
                        0, 0, 1, 1, 2, 2};

void solve() {
    int n, m;
    cin >> n >> m;

    bool change = false;
    if (m % 3) {
        change = true;
        swap(n, m);
    }
    if (n % 3 == 0 and m % 3 == 0 and n < m) {
        change = true;
        swap(n, m);
    }
    vector a(n, vector<int>(m));
    if (n <= 2) {
        if (m > 6) {
            cout << "No\n";
            return;
        }
        if (m == 3) {
            for (int i = 0; i < n; i++) {
                a[i] = {0, 1, 2};
            }
        } else {
            for (int i = 0; i < n; i++) {
                a[i] = {0, 0, 1, 1, 2, 2};
            }
        }
    } else if (n == 4) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = g[i][j % 6];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = f[i % 6][j % 6];
            }
        }
    }

    cout << "Yes\n";
    if (change) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[j][i];
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}