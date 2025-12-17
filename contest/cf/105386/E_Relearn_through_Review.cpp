#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

template <class T, T e, auto func>
struct SparseTable {
    int n;
    std::vector<std::vector<T>> a;
    SparseTable(const std::vector<T> &v = {}) {
        init(v);
    }
    void init(const std::vector<T> &v) {
        n = v.size();
        if (n == 0) {
            return;
        }
        const int m = std::__lg(n);
        a.assign(m + 1, std::vector<T>(n));
        a[0] = v;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i + (2 << j) <= n; i++) {
                a[j + 1][i] = func(a[j][i], a[j][i + (1 << j)]);
            }
        }
    }
    T operator()(int l, int r) const {
        if (l >= r) {
            return e;
        } else {
            const int k = std::__lg(r - l);
            return func(a[k][l], a[k][r - (1 << k)]);
        }
    }
};

void solve() {
    int n;
    i64 k;
    cin >> n >> k;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<i64, int> pre, suf;
    pre[0] = -1;
    suf[0] = n + 1;
    i64 g = 0;
    for (int i = 0; i < n; i++) {
        g = std::gcd(g, a[i]);
        pre[g] = i;
    }
    g = 0;
    for (int i = n - 1; i >= 0; i--) {
        g = std::gcd(g, a[i]);
        suf[g] = i + 1;
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::gcd(ans, a[i]);
    }

    for (int i = 0; i < n; i++) {
        a[i] += k;
    }
    SparseTable<i64, 0ll, [&](i64 x, i64 y) {
        return std::gcd(x, y);
    }> st(a);

    for (auto [gl, l] : pre) {
        for (auto [gr, r] : suf) {
            if (l + 1 >= r - 1) {
                continue;
            }
            i64 g = std::gcd(gl, gr);
            g = std::gcd(g, st(l + 1, r - 1));
            ans = max(ans, g);
        }
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