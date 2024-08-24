#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed;
    cerr << fixed << setprecision(2);
    
    int n, p;
    cin >> n >> p;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    auto check = [&](double t) {
        double now = 1. * p * t;
        for (int i = 0; i < n; i++) {
            double x = b[i] - t * a[i];
            if (x < 1e-8) {
                now += x;
            }
        }
        return now < 1e-8;
    };

    double lo = 0;
    double hi = 1e10;

    while (hi - lo > 1e-6) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << (lo - 1e10 > -1e-6 ? -1 : lo) << endl;
    
    return 0;
}