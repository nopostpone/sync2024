#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int sx, sy;
    cin >> sx >> sy;

    map<i64, set<i64>> f, g;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        f[x].insert(y);
        g[y].insert(x);
    }
    
    auto ydel = [&](i64 x, i64 y1, i64 y2) {
        if (not f.contains(x)) {
            return;
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        auto l = f[x].lower_bound(y1);
        auto r = f[x].upper_bound(y2);
        cerr << f[x].size() << endl;
        if (l != r) {
            f[x].erase(l, r);
        }
    };
    auto xdel = [&](i64 y, i64 x1, i64 x2) {
        if (not g.contains(y)) {
            return;
        }
        if (x1 > x2) {
            swap(x1, x2);
        }
        auto l = g[y].lower_bound(x1);
        auto r = g[y].upper_bound(x2);
        if (l != r) {
            g[y].erase(l, r);
        }
    };

    i64 x = sx, y = sy;
    for (int i = 0; i < m; i++) {
        char d;
        int c;
        cin >> d >> c;

        if (d == 'U') {
            ydel(x, y, y + c);
            y += c;
        } else if (d == 'D') {
            ydel(x, y, y - c);
            y -= c;
        } else if (d == 'L') {
            xdel(y, x, x - c);
            x -= c;
        } else {
            xdel(y, x, x + c);
            x += c;
        }
    }

    int ans = n;
    for (auto &[x, s] : f) {
        for (auto y : s) {
            if (g[y].contains(x)) {
                ans--;
            }
        }
    }
    cout << x << " " << y << " " << ans << "\n";

    return 0;
}