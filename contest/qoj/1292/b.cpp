#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> f(k);
    vector<i64> ans(n);
    if (m >= 2 * n) {
        i64 res = 0;
        vector<int> tem(n);
        for (int i = 0; i < 2 * n; i++) {
            int j = i % n;
            tem[j] += f[a[j]];
            f[a[j]] ^= 1;
        }
        int coef = m / (2 * n);
        for (int i = 0; i < n; i++) {
            ans[i] += i64(tem[i]) * coef;
        }
        m %= 2 * n;
    }
    for (int i = 0; i < m; i++) {
        int j = i % n;
        ans[j] += f[a[j]];
        f[a[j]] ^= 1;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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