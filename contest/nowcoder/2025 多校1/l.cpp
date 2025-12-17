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

void solve() {
    int n, q;
    cin >> n >> q;

    int need = n / 2;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = a;

    vector<pair<int, i64>> op(q);
    for (int i = 0; i < q; i++) {
        int p, v;
        cin >> p >> v;
        p--;
        b[p] += v;
        op[i] = {p, b[p]};
        a.push_back(b[p]);
    }

    auto va = a;
    ranges::sort(va);

    auto id = [&](i64 x) {
        auto it = lower_bound(va.begin(), va.end(), x);
        return int(it - va.begin());
    };

    Fenwick<int> fen(n + q);
    for (int i = 0; i < n; i++) {
        a[i] = id(a[i]);
        fen.add(a[i], 1);
    }

    for (auto [p, v] : op) {
        v = id(v);
        
        fen.add(a[p], -1);
        a[p] = v;
        fen.add(a[p], 1);

        int x = fen.select(n - need);
        cout << fen.sum(x) << "\n";
    }
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

/*
2
5 3
1 2 3 4 5
2 1
3 2
2 1
4 2
4 5 2 3
4 1
4 3

3
3
3
1
2
*/

