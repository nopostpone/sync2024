#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector f(n, vector<ll>(1 << n));
    for (int i = 1; i < n; i++)
        cin >> f[0][i];
    vector<int> dep(1 << n);
    for (int i = 1; i < dep.size(); i++) {
        dep[i] = log2(i);
    }

    function<void(int)> dfs = [&](int x) {
        if (x * 2 >= (1 << n)) {
            for (int i = 1; i <= n; i++) {
                f[i][x] = f[0][x];
            }
            return;
        }
        dfs(2 * x);
        dfs(2 * x + 1);
        for (int i = 1; i <= n; i++) {
            f[i][x] = f[0][x] + f[i - 1][x * 2] + f[i - 1][x * 2 + 1];
        }
    };
    dfs(1);

    vector<ll> res;
    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;
        if (x < y)
            swap(x, y);
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