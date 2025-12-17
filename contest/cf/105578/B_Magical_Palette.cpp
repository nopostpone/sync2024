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

    int v = n * m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        a[i] = (i * m + 1) % v;
    }
    for (int i = 0; i < m; i++) {
        b[i] = (i * n + 1) % v;
    }

    vector<bool> vis(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[((i64)a[i] * b[j]) % (n * m)] = true;
        }
    }
    if (ranges::count(vis, true) == n * m) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < m; i++) {
            cout << b[i] << " \n"[i == m - 1];
        }
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}