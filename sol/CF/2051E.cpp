#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 2>> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i][0];
        a[i][1] = (i >= n);
    }
    ranges::sort(a);

    ll ans{};
    int c{n};
    int x{};

    for (int i = 0; i < n * 2; i++) {
        if (i == 0 or a[i - 1][0] != a[i][0]) {
            if (x <= k) {
                ans = max(ans, 1ll * a[i][0] * c);
            }
        }
        if (a[i][1] == 0) {
            x++;
        } else {
            x--;
            c--;
        }
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}