#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (k--) {
        map<ll, vector<int>> f;
        for (int j = 0; j < m; j++) {
            ll t{};
            for (int i = 0; i < n; i++) {
                t += a[i][j];
            }
            f[t].push_back(j);
        }

        vector<bool> emp(m);
        vector<int> b;

        for (int j : f.rbegin()->second) {
            emp[j] = true;
            for (int i = 0; i < n; i++) {
                b.push_back(a[i][j]);
            }
        }
        for (int j : f.begin()->second) {
            if (emp[j]) {
                continue;
            }
            emp[j] = true;
            for (int i = 0; i < n; i++) {
                b.push_back(a[i][j]);
            }
        }
        ranges::sort(b);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < m; j++) {
                    if (emp[j]) {
                        a[i][j] = b.back();
                        b.pop_back();
                    }
                }
            } else {
                for (int j = m - 1; ~j; j--) {
                    if (emp[j]) {
                        a[i][j] = b.back();
                        b.pop_back();
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m - 1];
        }
    }

    return 0;
}