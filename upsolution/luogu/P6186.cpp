#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    Fenwick<int> fen(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        fen.add(a[i], 1);
        p[i] = fen.rangeSum(a[i] + 1, n);
    }

    Fenwick<ll> cnt(n), sum(n);
    for (int i = 0; i < n; i++) {
        cnt.add(p[i], 1);
        sum.add(p[i], p[i]);
    }

    ll P = accumulate(p.begin(), p.end(), 0ll);

    while (m--) {
        int o, x;
        cin >> o >> x;
        if (o == 1) {
            x--;
            if (a[x] < a[x + 1]) {
                cnt.add(p[x], -1);
                sum.add(p[x], -p[x]);
                p[x]++;
                P++;
                cnt.add(p[x], 1);
                sum.add(p[x], p[x]);
            } else {
                cnt.add(p[x + 1], -1);
                sum.add(p[x + 1], -p[x + 1]);
                p[x + 1]--;
                P--;
                cnt.add(p[x + 1], 1);
                sum.add(p[x + 1], p[x + 1]);
            }
            swap(a[x], a[x + 1]);
            swap(p[x], p[x + 1]);
        } else {
            x = min(n - 1, x);
            ll X = cnt.sum(x + 1);
            ll Y = sum.sum(x + 1);
            cout << (P -
                     1ll * n * x +
                     X * x -
                     Y)
                 << "\n";
        }
    }

    return 0;
}