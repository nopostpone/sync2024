#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto check = [&](int k) {
        i64 l = -1e18, r = 1e18;
        for (int i = 0; i < n; i++) {
            l = max(l, a[i] - (i64)k * b[i]);
            r = min(r, a[i] + (i64)k * b[i]);
        }
        return l <= r;
    };

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }

    cout << lo << "\n";
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
8 3 3 5
1 2 3 2
5
4 3 4 5 6
3 1 3 1 1

    2
    2
*/