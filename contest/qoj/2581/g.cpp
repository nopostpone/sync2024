#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<i64> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    ranges::sort(v, greater());
    ranges::sort(l);

    vector<i64> prev(n + 1), prel(n + 1);
    for (int i = 0; i < n; i++) {
        prev[i + 1] = prev[i] + v[i];
        prel[i + 1] = prel[i] + l[i];
    }

    int q;
    cin >> q;

    for (int _ = 0; _ < q; _++) {
        int t;
        cin >> t;

        int lo = 0, hi = n;
        while (lo < hi) {
            int x = midpoint(lo, hi);
            if (v[x] - 1ll * l[x] * t < 0) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }

        auto ans = prev[lo] - t * prel[lo];
        cout << ans << " \n"[_ == q - 1];
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
2
4
5 4 7 6
2 1 3 2
3
3 1 2
4
19 47 21 13
5 14 2 3
5
5 2 6 1 4
*/