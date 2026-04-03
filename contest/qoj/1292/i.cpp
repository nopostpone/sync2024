#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr auto work(int &h, int dam, i64 &cnt) {
    int th = min(cnt, (i64)h / dam);
    h -= th * dam;
    cnt -= th;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    array<i64, 3> oc {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        oc[a[i] - 1]++;
    }

    int m;
    cin >> m;

    vector<int> h(m);
    for (int i = 0; i < m; i++) {
        cin >> h[i];
    }

    auto check = [&](i64 t) {
        auto rest = h;
        array<i64, 3> c {};
        for (int i = 0; i < t % n; i++) {
            c[a[i] - 1]++;
        }
        for (int i = 0; i < 3; i++) {
            c[i] += (t / n) * oc[i];
        }

        for (auto &x : rest) {
            if (x % 2 == 1 and x >= 3 and c[2]) {
                x -= 3;
                c[2]--;
            }
        }
        i64 c6 = c[2] / 2;
        for (auto &x : rest) {
            if (x >= 6) {
                work(x, 6, c6);
            }
        }
        c[2] = c6 * 2 + (c[2] % 2);
        for (int i = 2; i >= 0; i--) {
            if (i < 2) {
                c[i] += c[i + 1];
            }
            for (auto &x : rest) {
                work(x, i + 1, c[i]);
            }
        }
        return ranges::count(rest, 0) == m;
    };

    i64 lo = 0, hi = accumulate(h.begin(), h.end(), i64());
    while (lo < hi) {
        auto x = midpoint(lo, hi);
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    cout << lo << "\n";
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