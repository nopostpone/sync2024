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
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    auto b = pre;
    ranges::sort(pre);

    for (auto &x : b) {
        x = lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }

    Fenwick<int> fen(n + 1);

    ll ans{};
    for (int i = 0; i < n + 1; i++) {
        ans += fen.sum(b[i] + 1);
        fen.add(b[i], 1);
        // cerr << b[i] << " " << ans << endl;
    }
    cout << ans;

    return 0;
}

