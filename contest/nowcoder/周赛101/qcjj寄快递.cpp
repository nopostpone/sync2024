#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << fixed << setprecision(18);

    double ans = 0;
    for (int i = 1; i < n; i++) {
        auto dis = sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1]));
        cerr << "dis = " << dis << endl;
        auto calc = [&](double k) {
            return k * 2 + dis * 2 / pow(2, k);
        };
        double res = 1e18;

        double lo = 0, hi = 100;
        while (hi - lo > 1e-6) {
            // cerr << lo << " " << hi << endl;
            double d = (hi - lo) / 3;
            double l = lo + d;
            double r = lo + 2 * d;

            double fl = calc(l);
            double fr = calc(r);
            res = min(res, fl);
            res = min(res, fr);
            if (fl < fr) {
                hi = r;
            } else {
                lo = l;
            }
        }
        ans += res;
    }

    cout << ans << "\n";

    return 0;
}