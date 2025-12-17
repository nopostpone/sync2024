#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> loc(n);
    for (int i = 0; i < 2 * n; i++) {
        loc[a[i]].push_back(i);
    }

    vector<bool> valid(n, true);
    for (int i = 1; i < 2 * n; i++) {
        if (a[i] == a[i - 1]) {
            valid[a[i]] = false;
        }
    }

    int ans = 0;
    for (int x = 0; x < n; x++) {
        if (not valid[x]) {
            continue;
        }
        int l = loc[x][0];
        int r = loc[x][1];

        map<int, int> f, g;
        if (l < 2 * n - 1) {
            f[a[l + 1]] = l + 1;
        }
        if (l) {
            f[a[l - 1]] = l - 1;
        }
        if (r) {
            g[a[r - 1]] = r - 1;
        }
        if (r < 2 * n - 1) {
            g[a[r + 1]] = r + 1;
        }
        for (auto [y, _] : f) {
            if (y <= x or not valid[y]) {
                continue;
            }
            if (g.contains(y)) {
                if (g[y] != f[y]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}