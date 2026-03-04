#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

template <typename T>
struct Fenwick {
    constexpr static int K = 64;
    int n;
    std::vector<int> a;

    std::vector<u64> mask, base;

    Fenwick() {}
    Fenwick(int n_) {
        n = (n_ >> 6) + 1;
        a.assign(n, T());
        mask.assign(K, 0);
        base.assign(n, 0);
        mask[0] = 1;

        for (int i = 1; i < K; i++) {
            mask[i] = mask[i - 1] << 1 | 1;
        }
    }
    void clear() {
        a.assign(n, T());
        base.assign(n, 0);
    }
    void add(int x, T v) {
        x++;
        int p = (x >> 6) + 1;
        int r = x & (K - 1);

        if ((base[p - 1] >> r) & 1) {
            return;
        }
        base[p - 1] ^= (1ull << r);
        while (p <= n) {
            a[p - 1] += v;
            p += p & -p;
        }
    }
    T sum(int x) {
        int p = (x >> 6);
        int r = x & (K - 1);
        T res = __builtin_popcountll(base[p] & mask[r]);
        while (p) {
            res += a[p - 1];
            p -= p & -p;
        }
        return res;
    }
};

constexpr int B = 500;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    const int nb = (n + B - 1) / B;
    vector<int> pl(nb), pr(nb);
    for (int i = 0; i < nb; i++) {
        pl[i] = i * B;
        pr[i] = min((i + 1) * B, n);
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<array<int, 3>>> ask(m);
    
    vector<i64> ans(m);
    Fenwick<int> fen(n);

    auto rangeAdd = [&](int l, int r, int t) {
        for (int i = l; i < r; i++) {
            fen.add(a[i], t);
        }
    };
    auto rangeQuery = [&](int l, int r) {
        i64 res = 0;
        for (int i = l; i < r; i++) {
            res += fen.sum(a[i]);
        }
        return res;
    };
    
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        ask[i].reserve(k);
        
        for (int j = 0; j < k; j++) {
            int l, r;
            cin >> l >> r;
            l--;
            
            int lb = l / B;
            int rb = (r - 1) / B;
            
            ask[i].push_back({l, r, j});

            if (lb == rb) {
                ans[i] += rangeQuery(l, r);
                rangeAdd(l, r, 1);
            } else {
                ans[i] += rangeQuery(l, pr[lb]);
                ans[i] += rangeQuery(pl[rb], r);
                rangeAdd(l, pr[lb], 1);
                rangeAdd(pl[rb], r, 1);
            }
        }

        fen.clear();
    }

    vector<int> p(m);
    
    vector<i64> pre(n + 1), suf(n + 1);
    auto work = [&](int l, int r) {
        vector<int> f(n + 1);
        for (int i = l; i < r; i++) {
            f[a[i] + 1]++;
        }
        for (int i = 0; i < n; i++) {
            f[i + 1] += f[i];
        }
        for (int i = 0; i < l; i++) {
            pre[i + 1] = pre[i] + f[n] - f[a[i]];
        }
        for (int i = n - 1; i >= r; i--) {
            suf[i] = suf[i + 1] + f[a[i] + 1];
        }

        for (int i = 0; i < m; i++) {
            while (p[i] < ask[i].size() and ask[i][p[i]][1] <= r) {
                p[i]++;
            }
            if (p[i] == ask[i].size() or ask[i][p[i]][0] >= l) {
                continue;
            }

            for (auto [u, v, j] : ask[i]) {
                if (j < p[i]) {
                    ans[i] += pre[v] - pre[u];
                } else if (j > p[i]) {

                    int ub = u / B;
                    int vb = (v - 1) / B;

                    if (ub == vb) {
                        ans[i] += suf[u] - suf[v];
                    } else {
                        ans[i] += suf[u] - suf[pr[ub]] + suf[pl[vb]] - suf[v];
                    }
                }
            }
        }
    };

    for (int i = 0; i < nb; i++) {
        work(pl[i], pr[i]);
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
}