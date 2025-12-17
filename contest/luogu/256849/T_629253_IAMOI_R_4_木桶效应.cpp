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

    int n, m, k, h;
    cin >> n >> m >> k >> h;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](i64 x) {
        i64 c1 = m;
        i64 ch = k;

        vector<i64> rest;
        for (int i = 0; i < n; i++) {
            if (a[i] >= x) {
                continue;
            }

            i64 d = x - a[i];
            i64 u = d / h;
            ch -= u;
            if (d % h != 0) {
                rest.push_back(d % h);
            }
        }

        if (ch < 0) {
            if (i128(h) * -ch > c1) {
                return false;
            }
            c1 += h * ch;
            ch = 0;
        }

        ranges::sort(rest, greater());
        for (auto r : rest) {
            if (ch > 0) {
                ch--;
                continue;
            } else {
                c1 -= r;
                if (c1 < 0) {
                    return false;
                }
            }
        }

        return true;
    };

    i64 lo = 0;
    i64 hi = ranges::max(a);
    hi += (i64)k * h + m + 1;
    while (lo < hi) {
        auto x = (lo + hi + 1) / 2;
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    cout << lo << "\n";

    return 0;
}