#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int inf = 1e9;

template<class T,
    class Cmp = std::less<T>>
struct RMQ {
    const Cmp cmp = Cmp();
    static constexpr unsigned B = 64;
    using u64 = unsigned long long;
    int n;
    std::vector<std::vector<T>> a;
    std::vector<T> pre, suf, ini;
    std::vector<u64> stk;
    RMQ() {}
    RMQ(const std::vector<T> &v) {
        init(v);
    }
    void init(const std::vector<T> &v) {
        n = v.size();
        pre = suf = ini = v;
        stk.resize(n);
        if (!n) {
            return;
        }
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
            return -inf;
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

void solve() {
    int n, L, k;
    cin >> n >> L >> k;

    vector<int> d(3 * n + 1);
    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        d[l]++;
        d[l + L]--;
        e.emplace_back(l, l + L);
    }
    for (int i = 1; i <= 3 * n; i++) {
        d[i] += d[i - 1];
    }

    vector<int> x(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        x[i] = (d[i] == k + 1) - (d[i] == k);
    }
    vector<int> y(4 * n);
    for (int i = 0; i < 3 * n; i++) {
        y[i] = (d[i] == k - 1) - (d[i] == k);
    }
    for (int i = 3 * n; i < 4 * n; i++) {
        y[i] = (0 == k - 1) - (0 == k);
    }

    vector<int> sx(3 * n + 1), sy(4 * n + 1);
    for (int i = 0; i < 3 * n; i++) {
        sx[i + 1] = sx[i] + x[i];
    }
    for (int i = 0; i < 4 * n; i++) {
        sy[i + 1] = sy[i] + y[i];
    }

    vector<int> pre(3 * n + 1, -inf), suf(pre);
    pre[0] = sy[L] - sy[0];
    for (int i = 1; i <= 3 * n; i++) {
        pre[i] = max(pre[i - 1], sy[i + L] - sy[i]);
    }
    suf[3 * n] = sy[3 * n + L] - sy[3 * n];
    for (int i = 3 * n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], sy[i + L] - sy[i]);
    }

    vector<int> fl(3 * n + 1);
    for (int i = 0; i < 3 * n; i++) {
        fl[i + 1] = fl[i] + x[i] + y[i + L];
    }
    RMQ<int, greater<>> rmql(fl);
    vector<int> fr(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
        fr[i] = x[i + L] + y[i];
    }
    for (int i = 2 * n; i > 0; i--) {
        fr[i - 1] += fr[i];
    }
    RMQ<int, greater<>> rmqr(fr);

    int ans = ranges::count(d, k);
    int dif = 0;
    for (auto [l, r] : e) {
        int ori = sx[r] - sx[l];
        int res = suf[r];
        if (l >= L) {
            res = max(res, pre[l - L]);
        }
        dif = max(dif, ori + res);

        dif = max(dif, rmql(l, l + L) - fl[l]);
        dif = max(dif, rmqr(max(0, l - L + 1), l) - fr[l]);
    }
    ans += dif;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}