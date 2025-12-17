#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

struct Vec {
    double x;
    double y;
    constexpr double operator^(const Vec &o) const {
        return x * o.y - y * o.x;
    }
};

inline double area(int x1, double y1, double x2, double y2, double x3, double y3) {
    Vec A = {x2 - x1, y2 - y1};
    Vec B = {x3 - x1, y3 - y1};
    return 0.5 * (A ^ B);
}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    double res = 2e18;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                double t = area(x[i], y[i], x[j], y[j], x[k], y[k]);
                t = fabs(t);
                if (t < 1e-9)
                    continue;
                res = min<double>(t, res);
            }
        }
    }
    if (res == 2e18) {
        res = -1;
    }
    cout << res << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}