#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<bool> vis(n), f(n);

    for (int _ = 0; _ < m; _++) {
        int a;
        cin >> a;

        if (vis[a - 1]) {
            cout << "the lights are already on!\n";
            continue;
        }
        vis[a - 1] = true;
        int res = 0;
        for (int i = a; i <= n; i += a) {
            res += not f[i - 1];
            f[i - 1] = true;
        }
        if (res != 0) {
            cout << res << "\n";
        } else {
            cout << "the lights are already on!\n";
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
}