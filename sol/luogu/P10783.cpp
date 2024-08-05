#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector f(n, vector<ll>(1 << n));
    for (int i = 1; i < n; i++)
        cin >> f[0][i];

    function<void(int)> dfs = [&](int x) {
        if (x * 2 > (1 << (n - 1))) {
            for ()
            return;
        }
        dfs(2 * x);
        dfs(2 * x + 1);
        for (int i = 1; i <= n; i++) {
            f[i][x] += f[i - 1][x * 2] + f[i - 1][x * 2 + 1];
        }
    };
    dfs(1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}