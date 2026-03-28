#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

double power(double a, i64 b) {
    double res = 1;
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    vector<int> c(n);
    auto check = [&](double v) {
        for (int i = 0; i < n; i++) {
            double num = 100 + l[i] - 100 * v;
            double den = l[i] * v - l[i];

            c[i] = max(0, (int)ceil(num / den));
        }
        return accumulate(c.begin(), c.end(), i64()) <= k;
    };

    double lo = 1, hi = 1 + (double)k * ranges::max(l) / 100;
    for (int _ = 0; _ < 50; _++) {
        double x = midpoint(lo, hi);
        if (check(x)) {
            hi = x;
        } else {
            lo = x;
        }
    }

    double ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 1 + (double)c[i] * l[i] / 100;
    }

    int sum = accumulate(c.begin(), c.end(), 0);
    double d = power(lo, abs(k - sum));
    if (sum > k) {
        ans /= d;
    } else if (sum < k) {
        ans *= d;
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
}