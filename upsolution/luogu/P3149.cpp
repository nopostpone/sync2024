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

    auto b = a;
    ranges::sort(b);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    const int N = *max_element(a.begin(), a.end()) + 1; // 值域

    Fenwick<int> fen(N);

    vector<ll> f(N);
    for (int i = n - 1; ~i; i--) {
        fen.add(a[i], 1);
        f[a[i]] += fen.sum(a[i]);
    }
    for (int i = 1; i < N; i++) {
        f[i] += f[i - 1];
    }
    cout << f.back() << "\n";

    int now{-1};
    while (m--) {
        int k;
        cin >> k;
        k--;

        if (now != -1 and a[k] < a[now]) {
            k = now;
        } else {
            now = k;
        }
        cout << f[N - 1] - f[a[k]] << "\n";
    }

    return 0;
}