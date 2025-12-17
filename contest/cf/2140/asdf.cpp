#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;
    
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    int k = n / 2;

    vector<pair<int, int>> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = pair(l[i] + r[i], i);
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += r[i] - l[i];
    }
    ranges::sort(f, greater());

    for (int i = 0; i < n; i++) {
        ans -= l[i];
    }
    vector<bool> vis(n);
    for (int i = 0; i < k; i++) {
        ans += f[i].first;
        vis[f[i].second] = true;
    }

    if (n % 2 == 1) {
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            add = max(add, l[i]);
        }
        ans += add;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}