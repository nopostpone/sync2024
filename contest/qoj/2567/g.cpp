#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    i64 n, k, m;
    cin >> n >> k >> m;

    i64 rest = n - n / k;
    i64 ans = m;

    if (rest >= m) {
        ans += (n / k - 1) / 2;
        ans += 1;
    } else {
        m -= rest;
        i64 x = n / k - m;
        if (x) {
            ans += (x - 1) / 2 + 1;
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
}

/*
2
4 1 0
5 3 1

*/