#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, k, a, b;
    cin >> n >> k >> a >> b;

    auto check = [&](i64 x) {
        i64 res = 0;

        for (i64 d = 1; d * (d - 1) <= 2 * k; d++) {
            i64 del = (x - b * d * 2 - a * d * d) / (a * d * 2);

            res += min(del, n - d);
            if (res >= k) {
                return true;
            }
            if (del == 0) {
                break;
            }
        }

        return false;
    };

    i64 lo = 1, hi = 6e18;
    while (lo < hi) {
        auto x = midpoint(lo, hi);
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }

    i64 ans = lo;
    i64 g = gcd(ans, a);

    ans /= g;
    a /= g;

    cout << ans << " " << a << "\n";
}

/*
1414215 1000000000000 1000000 1000000000000
*/