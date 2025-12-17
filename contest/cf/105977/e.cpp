#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    n *= 2;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<i64> pre[2]{};
    pre[0].assign(n + 1, 0);
    pre[1].assign(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        pre[i & 1][i + 1] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[0][i] += pre[0][i - 1];
        pre[1][i] += pre[1][i - 1];
    }

    vector<i64> d(n + 1);
    for (int i = 0; i <= n; i++) {
        d[i] = pre[0][i] - pre[1][i];
    }

    i64 ans = 1e18;
    set<i64> s[2] {};
    s[0].insert(d[0]);
    for (int r = 1; r <= n; r++) {
        int j = r & 1;

        auto it = s[j].lower_bound(-(d[n] - 2 * d[r]) / 2);
        if (it != s[j].end()) {
            ans = min(ans, abs(d[n] - d[r] * 2 + *it * 2));
        }
        if (it != s[j].begin()) {
            it = prev(it);
            ans = min(ans, abs(d[n] - d[r] * 2 + *it * 2));
        }
        s[j].insert(d[r]);
    }
    
    cout << (pre[0][n] + pre[1][n] - ans) / 2 << "\n";
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

/*
4
2
1 3 2 4
1
1000000000 1
3
1 1 2 3 5 8
4
1 2 4 8 16 32 64 128
*/