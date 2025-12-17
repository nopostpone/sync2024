#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    ranges::sort(a);

    while (q--) {
        int now;
        cin >> now;
        auto R = upper_bound(a.begin(), a.end(), now);
        auto L = R - 1;
        int l = 1, r = n;
        int res = 0;
        if (R == a.end()) {
            l = *L;
            res = n - l;
        } else if (L == a.end() or R == a.begin()) {
            r = *R;
            res = r - 1;
        } else {
            l = *L;
            r = *R;
            res = (r - l) / 2;
        }
        cout << res << endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}