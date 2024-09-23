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
    }
    vector<int> d(n, a[0]);
    for (int i = 1; i < n; i++) {
        d[i] = a[i] - a[i - 1];
    }

    Fenwick<int> f(n);
    for (int i = 0; i < n; i++) {
        f.add(i, d[i]);
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            ll k;
            cin >> x >> y >> k;
            x--, y--;

            f.add(x, k);
            if (y < n - 1)
                f.add(y + 1, -k);
        } else {
            int x;
            cin >> x;

            cout << f.sum(x) << "\n";
        }
    }
    
    return 0;
}