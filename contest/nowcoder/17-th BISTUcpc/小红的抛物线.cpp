#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    array<pair<int, int>, 3> a;

    int mn = 1e9;
    int mx = -1e9;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        mn = min(mn, y);
        mx = max(mx, y);
    }

    ranges::sort(a);
    if (a[1].second == mn) {
        cout << "UP\n";
    } else if (a[1].second == mx) {
        cout << "DOWN\n";
    } else {
        assert(a[0].first != a[1].first);

        double fx = double(a[0].second - a[1].second) / (a[0].first - a[1].first);
        fx *= (a[2].first - a[1].first);
        fx += a[1].second;

        cout << (a[2].second > fx ? "UP" : "DOWN") << "\n";
    }
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