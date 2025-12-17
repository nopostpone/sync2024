// https://atcoder.jp/contests/abc364/tasks/abc364_d
// 二分
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(q), k(q);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
        cin >> b[i] >> k[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++) {
        int lo = 0, hi = 2e8;
        while (lo < hi) {
            int x = lo + hi >> 1;

            int l = b[i] - x;
            int r = b[i] + x;
            int cnt = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
            if (cnt >= k[i]) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }
        cout << lo << "\n";
    }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}