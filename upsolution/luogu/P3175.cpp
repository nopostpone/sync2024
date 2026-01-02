#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int m = 1 << n;

    vector<double> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < m; s++) {
            if (~s >> i & 1) {
                p[s | 1 << i] += p[s];
            }
        }
    }

    double ans = 0;
    for (int s = 1; s < m; s++) {
        double f = 1 - p[(m - 1) ^ s];
        if (f == 0) {
            cout << "INF\n";
            return 0;
        }
        double e = 1. / f;
        if (__builtin_popcount(s) % 2) {
            ans += e;
        } else {
            ans -= e;
        }
    }
    cout << fixed << setprecision(15) << ans << "\n";

    return 0;
}
