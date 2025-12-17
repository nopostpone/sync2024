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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int m = *max_element(a.begin(), a.end()) + 1; // 值域小，没必要离散化

    vector<int> L(n), R(n);

    {
        Fenwick<int> fen(m);
        for (int i = 0; i < n; i++) {
            fen.add(a[i], 1);
            L[i] = fen.sum(a[i]);
        }
    }
    {
        Fenwick<int> fen(m);
        for (int i = n - 1; ~i; i--) {
            fen.add(a[i], 1);
            R[i] = fen.rangeSum(a[i] + 1, m);
        }
    }

    ll ans{};
    for (int i = 0; i < n; i++) {
        ans += L[i] * R[i];
    }
    cout << ans << endl;

    return 0;
}