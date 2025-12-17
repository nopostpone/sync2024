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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < n; i++) {
        int l = i - a[i] + 1;
        if (l >= 0 and a[l] <= a[i]) {
            vec[l].push_back(i + 1);
        }
        int r = i + a[i];
        if (r <= n and a[r - 1] <= a[i]) {
            vec[i].push_back(r);
        }
    }

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        if (not vec[i].empty()) {
            f[i] = ranges::max(vec[i]);
        } else {
            f[i] = i;
        }
    }

    for (int i = 1; i < n; i++) {
        f[i] = max(f[i], f[i - 1]);
    }

    int ans = 0;

    for (int i = 0; i < n; i = f[i]) {
        ans++;
        if (i != n and i == f[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}