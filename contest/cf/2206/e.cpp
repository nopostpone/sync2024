#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

constexpr int B = 631;

template<class T, T e, class Cmp = std::less<T>>
struct SparseTable {
    const Cmp cmp = Cmp();
    static constexpr unsigned B = 64;
    int n;
    std::vector<std::vector<T>> a;
    std::vector<T> pre, suf, ini;
    std::vector<u64> stk;
    SparseTable(const std::vector<T> &v = {}) {
        init(v);
    }
    void init(const std::vector<T> &v) {
        n = v.size();
        if (n == 0) {
            return;
        }
        pre = suf = ini = v;
        stk.resize(n);
        const int M = (n - 1) / B + 1;
        const int lg = std::__lg(M);
        a.assign(lg + 1, std::vector<T>(M));
        for (int i = 0; i < M; i++) {
            a[0][i] = v[i * B];
            for (int j = 1; j < B && i * B + j < n; j++) {
                a[0][i] = std::min(a[0][i], v[i * B + j], cmp);
            }
        }
        for (int i = 1; i < n; i++) {
            if (i % B) {
                pre[i] = std::min(pre[i], pre[i - 1], cmp);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (i % B != B - 1) {
                suf[i] = std::min(suf[i], suf[i + 1], cmp);
            }
        }
        for (int j = 0; j < lg; j++) {
            for (int i = 0; i + (2 << j) <= M; i++) {
                a[j + 1][i] = std::min(a[j][i], a[j][i + (1 << j)], cmp);
            }
        }
        for (int i = 0; i < M; i++) {
            const int l = i * B;
            const int r = std::min(1U * n, l + B);
            u64 s = 0;
            for (int j = l; j < r; j++) {
                while (s && cmp(v[j], v[std::__lg(s) + l])) {
                    s ^= 1ULL << std::__lg(s);
                }
                s |= 1ULL << (j - l);
                stk[j] = s;
            }
        }
    } 
    T operator()(int l, int r) {
        if (l >= r) {
            return e;
        }
        if (l / B != (r - 1) / B) {
            T ans = std::min(suf[l], pre[r - 1], cmp);
            l = l / B + 1;
            r = r / B;
            if (l < r) {
                int k = std::__lg(r - l);
                ans = std::min({ans, a[k][l], a[k][r - (1 << k)]}, cmp);
            }
            return ans;
        } else {
            int x = B * (l / B);
            return ini[__builtin_ctzll(stk[r - 1] >> (l - x)) + l];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> s(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        cin >> s[i];
    }
    vector<i64> w(n);
    for (int i = m; i < n; i++) {
        w[i] = s[i - m + 1] - s[i - m] + w[i - m];
    }

    int q;
    cin >> q;

    auto ans = [&](i64 sum) {
        i64 ans;
        if (s[0] + sum < 0) {
            ans = (s[0] + sum) / m;
        } else {
            ans = (s[0] + sum + m - 1) / m;
        }
        cout << ans << "\n";
    };
    
    if (m <= B) {
        vector<SparseTable<i64, 0, greater<>>> rmq(m);
        for (int i = 0; i < m; i++) {
            vector<i64> init;
            init.reserve((n + m - 1) / m);
            for (int j = i; j < n; j += m) {
                init.push_back(w[j]);
            }
            rmq[i].init(init);
        }
        for (int _ = 0; _ < q; _++) {
            int l, r;
            cin >> l >> r;
            l--;
            
            if (r - l < m) {
                cout << "unbounded\n";
                continue;
            }
            i64 sum = 0;
            for (int i = 0; i < m; i++) {
                int tl = (l - i + m - 1) / m;
                int tr = (r - 1 - i) / m + 1;
                sum += rmq[i](tl, tr);
            }
            
            ans(sum);
        }
    } else {
        const int k = (n + m - 1) / m;
        vector f(k, vector(k, vector(m + 1, i64())));
        
        for (int i = 0; i < m; i++) {
            for (int l = 0; l < k; l++) {
                if (l * m + i >= n) {
                    continue;
                }
                i64 cur = w[l * m + i];
                for (int r = l; r < k; r++) {
                    if (r * m + i < n) {
                        cur = max(cur, w[r * m + i]);
                    }
                    f[l][r][i + 1] = cur;
                }
            }
        }
        for (int l = 0; l < k; l++) {
            for (int r = l; r < k; r++) {
                for (int i = 0; i < m; i++) {
                    f[l][r][i + 1] += f[l][r][i];
                }
            }
        }

        auto safeSum = [&](int u, int v, int l, int r) {
            if (u < 0 or u >= k or v < 0 or v >= k or l >= r) {
                return i64();
            }
            return f[u][v][r] - f[u][v][l];
        };

        for (int _ = 0; _ < q; _++) {
            int l, r;
            cin >> l >> r;
            l--;

            if (r - l < m) {
                cout << "unbounded\n";
                continue;
            }

            int lb = l / m;
            int rb = (r - 1) / m;

            int x1 = l % m;
            int x2 = (r - 1) % m;

            i64 sum = 0;

            if (x1 <= x2) {
                sum = safeSum(lb + 1, rb, 0, x1) +
                    safeSum(lb, rb, x1, x2 + 1) +
                    safeSum(lb, rb - 1, x2 + 1, m);
            } else {
                sum = safeSum(lb + 1, rb, 0, x2 + 1) +
                    safeSum(lb + 1, rb - 1, x2 + 1, x1) +
                    safeSum(lb, rb - 1, x1, m);
            }
            ans(sum);
        }
    }
}