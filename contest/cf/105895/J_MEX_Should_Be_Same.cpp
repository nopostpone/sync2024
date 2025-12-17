#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector a(n, vector<int>(n));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            cnt += a[i][j] == 0;
        }
    }

    if (cnt <= n * n / 2) {
        for (int i = 0; i < n; i++) {
            for_each(a[i].begin(), a[i].end(), [](int &x) {
                if (x == 0) {
                    x = 1;
                }
            });
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                if (a[i][j] == 1) {
                    a[i][j] = 2;
                }
            }
            if (a[i][i] != 0) {
                a[i][i] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
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