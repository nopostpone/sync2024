#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    auto dot = [&](int i, int j) {
        return x[i] * x[j] + y[i] * y[j];
    };
    auto cross = [&](int i, int j) {
        return x[i] * y[j] - x[j] * y[i];
    };
    auto syn = [&](int i) {
        return (y[i] > 0 or (y[i] == 0 and x[i] > 0)) ? 1 : -1;
    };
    auto square = [&](int i) {
        return x[i] * x[i] + y[i] * y[i];
    };

    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        if (syn(i) != syn(j)) {
            return syn(i) == 1;
        }
        return cross(i, j) > 0;
    });

    struct Info {
        i64 num;
        i64 den;
        int a;
        int b;
        int s;

        bool operator<(const Info &rhs) const {
            if (s != rhs.s) {
                return s > rhs.s;
            }
            return ((i128)num * rhs.den - (i128)rhs.num * den) * s > 0;
        }
    };

    Info ans{inf, 1, 0, 0, -1};
    for (int i = 0; i < n; i++) {
        int a = ord[i];
        int b = ord[(i + 1) % n];

        i64 num = (i64)dot(a, b) * dot(a, b);
        i64 den = (i64)square(a) * square(b);
        int s = dot(a, b) > 0 ? 1 : -1;

        ans = min(ans, Info{num, den, a, b, s});
    }

    cout << ans.a + 1 << " " << ans.b + 1 << "\n";

    return 0;
}
