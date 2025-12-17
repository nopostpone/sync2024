#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n, x, y, k;
    cin >> n >> x >> y >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> px(n + 1), py(n + 1);
    px[n] = py[n] = n;
    vector<int> pk(n + 1);
    pk[n] = n;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == x) {
            px[i] = i;
        } else {
            px[i] = px[i + 1];
        }
        if (a[i] == y) {
            py[i] = i;
        } else {
            py[i] = py[i + 1];
        }
        if (a[i] == k or a[i] > x or a[i] < y) {
            pk[i] = i;
        } else {
            pk[i] = pk[i + 1];
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int l = max(px[i], py[i]);
        int r = pk[i];

        ans += max(0, r - l);
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

    return 0;
}