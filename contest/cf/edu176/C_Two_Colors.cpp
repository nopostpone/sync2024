#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    ranges::sort(a);
    
    i64 ans = 0;
    i64 t = 2;
    for (int x = 1; x <= n / 2; x++) {
        if (x == n / 2 and n % 2 == 0) {
            t = 1;
        }
        int y = n - x;
        i64 u = lower_bound(a.begin(), a.end(), x) - a.begin();
        u = m - u;
        i64 v = lower_bound(a.begin(), a.end(), y) - a.begin();
        v = m - v;
        u -= v;

        if (v) {
            ans += t * v * (v - 1);
        }
        if (u) {
            ans += t * u * v;
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