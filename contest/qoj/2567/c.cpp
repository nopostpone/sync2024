#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<i64> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    auto adjust = [&](auto a) {
        vector<int> ord(a.size());
        ranges::iota(ord, 0);
        ranges::sort(ord, [&](int i, int j) {
            return a[i] < a[j];
        });

        for (int i = 1; i < a.size(); i++) {
            int x = ord[i - 1], y = ord[i];
            a[y] = max(a[y], a[x] + 2 * k);
        }
        return move(a);
    };

    a = adjust(move(a));
    b = adjust(move(b));

    auto norm = [&](i64 x) {
        x %= (2 * k);
        if (x >= 2 * k) {
            x -= 2 * k;
        }
        if (x < 0) {
            x += 2 * k;
        }
        return x;
    };
    auto get = [&](const auto &a, const auto &b) {
        auto x = ranges::max(a);
        auto y = ranges::max(b);

        auto d = norm(x + k - y);
        return max(x, y + d) + k;
    };

    int l = 0, r = 1;
    i64 x = get(a, b);
    i64 y = get(b, a);

    if (x > y) {
        swap(n, m);
        swap(a, b);
        swap(l, r);
        swap(x, y);
    }

    i64 A = ranges::max(a);
    for (auto &x : a) {
        i64 d = norm(A - x);
        x += d;
    }
    for (auto &x : b) {
        i64 d = norm(A - x + k);
        x += d;
    }

    vector<tuple<i64, int, int>> ans;
    for (int i = 0; i < n; i++) {
        ans.emplace_back(a[i], l, i);
    }
    for (int i = 0; i < m; i++) {
        ans.emplace_back(b[i], r, i);
    }

    cout << x << "\n";

    ranges::sort(ans);
    for (auto [t, p, i] : ans) {
        cout << t << " " << p << " " << i + 1 << "\n";
    }
}