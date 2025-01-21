#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 1ll * n * (n + 1) / 2;
    for (int x = 1; x <= 10; x++) {
        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + (a[i] > x ? 1 : -1);
        }
        vector<int> cnt(2 * n + 1);
        int L = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] == x) {
                while (L < i) {
                    cnt[f[L] + n]++;
                    L++;
                }
            }
            ans -= cnt[f[i] + n];
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
