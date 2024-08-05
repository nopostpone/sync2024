#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    int num = 1 << n;
    ll sum = 0;
    vector f(num, vector<ll>(2 * n));
    vector g(num, vector<ll>(2 * n));
    for (int i = 1; i < num; i++) {
        cin >> f[i][0];
        sum += f[i][0];
    }

    vector<int> dep(num);
    for (int i = 1; i < dep.size(); i++) {
        dep[i] = log2(i);
    }

    function<void(int)> dfs1 = [&](int x) {
        if (x * 2 >= num) {
            for (int i = 1; i <= 2 * n - 2; i++) {
                f[x][i] = f[x][0];
            }
            return;
        }
        dfs1(2 * x);
        dfs1(2 * x + 1);
        for (int i = 1; i <= 2 * n - 2; i++) {
            f[x][i] = f[x * 2][i - 1] + f[x * 2 + 1][i - 1] + f[x][0];
        }
    };
    function<void(int)> dfs2 = [&](int x) {
        if (x >= num) {
            return;
        }
        g[x][0] = f[x][0];
        if (x == 1) {
            for (int i = 1; i <= 2 * n - 2; i++) {
                g[x][i] = f[x][0];
            }
        } else {
            for (int i = 1; i <= 2 * n - 2; i++) {
                g[x][i] = g[x / 2][i - 1] + f[x / 2][i - 1] - f[x / 2][0] + f[x][0];
                if (i >= 2)
                    g[x][i] -= f[x][i - 2];
            }
        }
        dfs2(x * 2);
        dfs2(x * 2 + 1);
    };

    dfs1(1);
    dfs2(1);

    auto lca = [&](int u, int v) {
        while (u / 2 != v / 2) {
            if (u > v) {
                u /= 2;
            } else {
                v /= 2;
            }
        }
        return u / 2;
    };

    auto dist = [&](int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    };

    vector<ll> res;
    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;
        if (k >= (2 * n - 2)) {
            res.push_back(sum);
            continue;
        }
        int d = dist(x, y) / 2;
        if (x == y) {
            res.push_back(f[lca(x, y)][k - d] + g[lca(x, y)][k - d]);
            continue;
        }
        if (x < y)
            swap(x, y);
        if ((dep[x] - dep[y]) & 1) {
            int mid1 = x, mid2 = y;
            for (int i = 1; i <= d; i++) {
                mid1 /= 2;
            }
            mid2 = mid1 / 2;
        } else {
            int mid = x;
            for (int i = 1; i <= d; i++) {
                mid /= 2;
            }
            res.push_back(f[mid][k - d] + g[mid][k - d]);
        }
    }
    for (auto i : res)
        cout << i << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}