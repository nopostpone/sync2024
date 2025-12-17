#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << n << "\n";
        return;
    }

    int cnt = 0;
    ll y = k;
    while (y * k <= n) {
        y *= k;
    }
    while (y != 1) {
        if (n - y >= 0) {
            cnt++;
            n -= y;
        } else {
            y /= k;
        }
    }
    if (y == 1) {
        cnt += n;
    }
    
    cout << cnt << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}