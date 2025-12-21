#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    vector<i64> ans(n);
    for (int r = n - 1, l = 0; r > 0; r--, l = max(0, l - 1)) {
        while (l < r and a[r] < pre[r] - pre[l]) {
            ans[r - l] = pre[r + 1] - pre[l];
            l++;
        }
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
/*
7
5
1 2 3 4 5
5
1 2 4 8 16
5
2 2 2 2 2
4
1 4 10 7
2
1 2
3
2 3 4
4
3 1 2 6
*/