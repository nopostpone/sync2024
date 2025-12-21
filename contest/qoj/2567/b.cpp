#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr i64 inf = 1e18;
using Mat = array<array<i64, 64>, 64>;

constexpr auto chmax(auto &a, auto b) {
    if (b > a) {
        a = b;
    }
}

constexpr Mat operator*(const auto &a, const auto &b) {
    Mat c;
    for (int i = 0; i < 64; i++) {
        c[i].fill(-inf);
    }
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            for (int k = 0; k < 64; k++) {
                chmax(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return move(c);
}
const auto power(auto a, i64 b) {
    Mat res;
    for (int i = 0; i < 64; i++) {
        res[i].fill(-inf);
        res[i][i] = 0;
    }

    for (; b; b /= 2, a = a * a) {
        if (b & 1) {
            res = res * a;
        }
    }
    return move(res);
}

void solve() {
    int n, m, k, r;
    cin >> n >> m >> k >> r;

    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
    }
    int mask = 1 << n;

    vector<int> cost(mask), damage(mask);
    for (int s = 0; s < mask; s++) {
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
                cost[s] += c[i];
                damage[s] += a[i];
            }
        }
        if (cost[s] > m) {
            damage[s] = 0;
        }
    }

    Mat f {};
    for (int s = 0; s < mask; s++) {
        for (int t = 0; t < mask; t++) {
            int cnt = __builtin_popcount(s & t);
            if (cost[t] + cnt * k <= m) {
                f[s][t] = damage[t];
            }
        }
    }

    f = power(f, r);
    i64 ans = -inf;
    for (int s = 0; s < mask; s++) {
        chmax(ans, f[0][s]);
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

    return 0;
}

/*
3
3 7 1 5
59 3
13 2
81 4
5 14 2 9
66 8
20 2
25 4
39 6
57 7
4 13 7 16
18 2
13 5
33 4
7 1
*/