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

    cout << fixed << setprecision(15);

    int n, k;
    cin >> n >> k;

    vector<int> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
        x[i] *= 2;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    ranges::sort(p, [&](int i, int j) {
        return x[i] < x[j];
    });

    auto check = [&](int t) {
        deque<i64> q;
        i64 cnt{};
        for (auto i : p) {
            if (v[i] == 1) {
                q.push_back(x[i]);
            } else {
                while (not q.empty() and q.front() + 2 * t < x[i]) {
                    q.pop_front();
                }
                cnt += q.size();
            }
        }
        return cnt >= k;
    };

    int lo = 0, hi = 1e9 + 10;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (check(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    if (lo == 1e9 + 10) {
        cout << "No\n";
    } else {
        cout << "Yes\n" << lo / 2;
        if (lo % 2) {
            cout << ".5" << "\n";
        }
    }

    return 0;
}   