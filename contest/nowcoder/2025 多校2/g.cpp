#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;

const double PI = acos(-1);

void solve() {
    int n;
    i64 bx, by;
    cin >> n >> bx >> by;

    vector<i64> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    bool inside = true;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;

        i64 dx = x[j] - x[i];
        i64 dy = y[j] - y[i];

        i64 rx = bx - x[i];
        i64 ry = by - y[i];

        if (dx * ry - dy * rx < 0) {
            inside = false;
        }
    }

    if (not inside) {
        cout << 2 * PI << "\n";
        return;
    }

    vector<i64> dis(n);
    for (int i = 0; i < n; i++) {
        dis[i] = (x[i] - bx) * (x[i] - bx) + (y[i] - by) * (y[i] - by);
    }
    auto D = ranges::max(dis);

    vector<double> angles;
    for (int i = 0; i < n; i++) {
        if (dis[i] == D) {
            angles.push_back(atan2l(y[i] - by, x[i] - bx));
        }
    }
    ranges::sort(angles);

    double ans = 0;
    const int m = angles.size();
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, angles[i + 1] - angles[i]);
    }
    ans = max(ans, angles[0] - angles[m - 1] + 2 * PI);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(18);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}