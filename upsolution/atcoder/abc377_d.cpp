#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ranges::sort(a, [](auto x, auto y) { return x.second - x.first < y.second - y.first; });
    
    set<pair<int, int>> b;
    for (auto [x, y] : a) {
        if (b.empty()) {
            b.emplace(x, y);
            continue;
        }
        auto it = b.lower_bound(make_pair(x, y));
        if (it != b.end() and y >= it->second) {
            continue;
        }
        b.emplace(x, y);
    }

    ll ans = 1ll * m * (m + 1) / 2;

    int pos = 0;
    int lst = -1;
    for (auto [x, y] : b) {
        if (x == lst) {
            continue;
        } else {
            lst = x;
        }
        ans -= 1ll * (x - pos) * (m - y + 1);
        pos = x;
    }
    cout << ans << endl;
    
    return 0;
}