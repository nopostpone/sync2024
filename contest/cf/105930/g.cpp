#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int w, t;
        cin >> w >> t;
        a[i] = w - t;
    }
    ranges::sort(a);

    int cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1]) {
            cnt++;
        } else {
            int d = a[i + 1] - a[i] - 1;
            cnt = max(0, cnt - d);
        }
    }

    cout << 1ll * k - a[0] + cnt << "\n";
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
 2
 4 3
 3 2
 2 1
 3 2
 1 2
 2 10
 1 7
 4 20

1
10 4
4 1
4 1
4 1
4 1
4 1
4 1
4 1
4 1
4 1
3 2
*/