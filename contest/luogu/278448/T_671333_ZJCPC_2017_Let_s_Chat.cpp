#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<pair<int, int>> a(x), b(y);
    for (auto &[l, r] : a) {
        cin >> l >> r;
        l--;
    }
    for (auto &[l, r] : b) {
        cin >> l >> r;
        l--;
    }

    int ans = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int L = max(a[i].first, b[j].first);
            int R = min(a[i].second, b[j].second);

            ans += max(0, R - L - m + 1);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}