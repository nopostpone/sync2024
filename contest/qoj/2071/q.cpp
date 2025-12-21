#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 1;
    auto check = [&](int i) {
        return a[i + 3] - 3 * a[i + 2] + 3 * a[i + 1] - a[i] == 0;
    };

    for (int i = 0, j = 0; i < n; i++) {
        if (i - j >= 3 and not check(i - 3)) {
            j = i;
            ans++;
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
4
12
-16 -9 -4 -1 0 0 0 0 1 4 9 16
8
2 0 2 5 0 3 0 8
1
0
5
1000000000000000000 250000000000000000 0 250000000000000000 1000000000000000000

*/