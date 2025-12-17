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
        dep[i] = dep[i / 2] + 1;
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

    auto getlca = [&](int u, int v) {
        if (u == 1 or v == 1) {
            return 1;
        }
        while (u / 2 != v / 2) {
            if (u > v) {
                u /= 2;
            } else {
                v /= 2;
            }
            if (u == v) {
                return u;
            }
        }
        return u / 2;
    };


    vector<ll> res;
    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;
        if (k >= (2 * n - 2)) {
            res.push_back(sum);
            continue;
        }
        int xx = x, yy = y;
        int lca = getlca(x, y);
        int mx, my, lasx = 0, lasy = 0;
        ll tmp = 0;
        while (xx != yy) {
            if (dep[xx] < dep[yy]) {
                swap(x, y);
                swap(xx, yy);
                swap(lasx, lasy);
            }
            mx = max(dep[x] - dep[xx], dep[y] + dep[xx] - dep[lca] * 2);
            if (mx <= k) {
                tmp += f[xx][k - mx];
                if (k > mx) {
                    tmp -= f[lasx][k - mx - 1];
                }
            }
            lasx = xx;
            xx /= 2;
        }
        mx = max(dep[x] - dep[lca], dep[y] - dep[lca]);
        if (mx <= k) {
            tmp += f[lca][k - mx] + g[lca][k - mx] - f[lca][0];
            if (k > mx) {
                tmp -= f[lasx][k - mx - 1] + f[lasy][k - mx - 1];
            }
        }
        res.push_back(tmp);        
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