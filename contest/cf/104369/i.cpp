#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    vector<pair<int, int>> pos(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            pos[a[i][j]] = {i, j};
        }
    }

    vector f(n + 5, vector<int>(m + 5));
    auto sum = [&](int d, int e) {
        int u = d;
        int ans = 0;
        while (u) {
            int v = e;
            while (v) {
                ans += f[u][v];
                v -= (v & -v);
            }
            u -= (u & -u);
        }
        return ans;
    };
    auto add = [&](int i, int j, int k) {
        int u = i;
        while (u <= n) {
            int v = j;
            while (v <= m) {
                f[u][v] += k;
                v += (v & -v);
            }
            u += (u & -u);
        };
    };
    auto rangeAdd = [&](int a, int b, int d, int e) {
        add(a, b, 1);
        add(a, e + 1, -1);
        add(d + 1, b, -1);
        add(d + 1, e + 1, 1);
    };

    int mex = 0;
    while (mex < n * m) {
        auto [x, y] = pos[mex];
        x++;
        y++;

        if (sum(x, y)) {
            break;
        }

        rangeAdd(x + 1, 1, n + 1, y - 1);
        rangeAdd(1, y + 1, x - 1, m + 1);
        mex++;
    }
    cout << mex << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
/*
2
2 3
1 2 4
3 0 5
1 5
1 3 0 4 2
*/