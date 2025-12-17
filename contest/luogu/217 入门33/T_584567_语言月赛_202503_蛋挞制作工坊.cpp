#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> g(m);
    for (int i = 0; i < m; i++) {
        cin >> g[i];
    }

    vector c(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }

    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        int cnt = 1e9;
        for (int j = 0; j < m; j++) {
            cnt = min(cnt, c[i][j] / g[j]);
        }
        e[i] = cnt;
        for (int j = 0; j < m; j++) {
            c[i][j] -= cnt * g[j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    
    for (int x = 0; x < m; x++) {
        ranges::sort(p, [&](int i, int j) {
            if (c[i][x] == c[j][x]) {
                if (e[i] == e[j]) {
                    return i < j;
                }
                return e[i] > e[j];
            }
            return c[i][x] < c[j][x];
        });

        for (auto x : p) {
            cout << x + 1 << " \n"[x == p.back()];
        }
    }

    return 0;
}