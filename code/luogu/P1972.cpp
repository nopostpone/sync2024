#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<array<int, 3>> que(m);
    for (int i = 0; i < m; i++) {
        cin >> que[i][1] >> que[i][2];
        que[i][1]--;
        que[i][0] = i;
    }
    ranges::sort(que, [](auto i, auto j) {
        return i[2] < j[2];
    });

    Fenwick<int> fen(n);
    map<int, int> f;

    vector<int> ans(m);
    for (int q = 0, i = 0; q < m; q++) {
        auto [id, l, r] = que[q];
        while (i < r) {
            if (f.contains(a[i])) {
                fen.add(f[a[i]], -1);
            }
            f[a[i]] = i;
            fen.add(i, 1);
            i++;
        }
        ans[id] = fen.rangeSum(l, r);
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}