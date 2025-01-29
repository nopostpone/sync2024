#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <class T, class Cmp = std::less<T>>
struct SparseTable {
    const int n;
    const int logn;

    const Cmp cmp = Cmp();
    std::vector<std::vector<T>> jump;

    constexpr SparseTable(const std::vector<T> &a)
        : n{a.size()}, logn{std::__lg(n)}, jump(logn + 1) {

        jump[0] = a;

        for (int j = 1; j <= logn; j++) {
            jump[j].resize(n - (1 << j) + 1);
        }

        for (int j = 0; j < logn; j++) {
            const int limit = n - (1 << (j + 1));
            for (int i = 0; i <= limit; i++) {
                jump[j + 1][i] = std::min(jump[j][i], jump[j][i + (1 << j)], cmp);
            }
        }
    }

    // [l, r)
    constexpr T operator()(int l, int r) const {
        assert(l < r and r <= n);
        const int layer = std::__lg(r - l);
        return std::min(jump[layer][l], jump[layer][r - (1 << layer)], cmp);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    SparseTable<int> mn(a);
    SparseTable<int, greater<int>> mx(a);
    auto Same = [&](int l, int r) {
        l--;
        if (r - l == 1) {
            return false;
        }
        return mn(l, r) == mx(l, r);
    };

    auto work = [&](int id) {
        if (id - 1) {
            if (a[id - 2] > a[id - 1]) {
                return 1;
            }
        }
        if (id < n) {
            if (a[id] > a[id - 1]) {
                return 1;
            }
        }
        int ans = n;
        if (id > 1) {
            int lo = 0, hi = id - 1;
            while (lo < hi) {
                int m = (lo + hi + 1) / 2;
                if (not Same(m, id - 1) and pre[id - 1] - pre[m - 1] > a[id - 1]) {
                    lo = m;
                } else {
                    hi = m - 1;
                }
            }
            if (lo != 0) {
                ans = id - lo;
            }
        }
        if (id < n) {
            int lo = id + 1, hi = n + 1;
            while (lo < hi) {
                int m = (lo + hi) / 2;
                if (not Same(id + 1, m) and pre[m] - pre[id] > a[id - 1]) {
                    hi = m;
                } else {
                    lo = m + 1;
                }
            }
            if (lo != n + 1) {
                ans = min(ans, lo - id);
            }
        }

        if (ans == n) {
            return -1;
        }
        return ans;
    };
    for (int i = 0; i < n; i++) {
        cout << work(i + 1) << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}