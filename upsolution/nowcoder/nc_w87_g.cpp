// https://ac.nowcoder.com/acm/contest/73854/G
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

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> ip(n + 1);
    for (int i = 0; i < n; i++) {
        ip[p[i]] = i;
    }

    auto F = [&](int d) {
        vector<int> tem;
        for (int i = d; i <= n; i += d) {
            tem.push_back(i);
        }
        ranges::sort(tem, [&](int i, int j) {
            return ip[i] > ip[j];
        });

        Fenwick<int> fen(tem.size() + 1);

        ll res{};
        for (auto x : tem) {
            res += fen.sum(x / d);
            fen.add(x / d, 1);
        }
        return res;
    };

    vector<int> mu(n + 1);
    mu[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j < n; j += i) {
            mu[j] -= mu[i];
        }
    }

    ll ans{};
    for (int i = 1; i <= n; i++) {
        ans += F(i) * mu[i];
    }
    cout << ans << "\n";

    return 0;
}