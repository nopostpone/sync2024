#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
struct RMQidx {
    const int n;
    const int logn;
    
    std::vector<T> a;
    std::vector<std::vector<int>> jump;

    constexpr RMQidx(const std::vector<T> &init)
        : n{(int)init.size()}, logn{std::__lg(n)}, jump(logn + 1), a(init) {

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        auto comp = [&](auto x, auto y) {
            return this->a[x] < this->a[y];
        };
        
        jump[0] = id;

        for (int j = 1; j <= logn; j++) {
            jump[j].resize(n - (1 << j) + 1);
        }

        for (int j = 0; j < logn; j++) {
            const int limit = n - (1 << (j + 1));
            for (int i = 0; i <= limit; i++) {
                jump[j + 1][i] = std::min(jump[j][i], jump[j][i + (1 << j)], comp);
            }
        }
    }

    constexpr int operator()(int l, int r) const {
        int log = std::__lg(r - l);
        return std::min(jump[log][l], jump[log][r - (1 << log)], [&](auto x, auto y) {
            return this->a[x] < this->a[y];
        });
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

    // {l, r, id}
    vector<array<int, 3>> q(m);
    for (int i = 0; i < m; i++) {
        for (int j : {0, 1}) {
            cin >> q[i][j];
            q[i][j]--;
        }
        q[i][2] = i;
    }

    // 离线排序
    const int len = sqrt(n);
    sort(q.begin(), q.end(), [&len](auto x, auto y) {
        if (x[0] / len == y[0] / len) {
            if ((x[0] / len) % 2 == 1) {
                return x[1] > y[1];
            } else {
                return x[1] < y[1];
            }
        }
        return x[0] < y[0];
    });

    // 单调栈
    vector<int> Lless(n, -1), Rless(n, n);

    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (not stk.empty() and a[stk.top()] >= a[i]) {
            stk.pop();
        }
        if (not stk.empty()) {
            Lless[i] = stk.top();
        }
        stk.push(i);
    }
    stk = stack<int>();
    for (int i = n - 1; ~i; i--) {
        while (not stk.empty() and a[stk.top()] >= a[i]) {
            stk.pop();
        }
        if (not stk.empty()) {
            Rless[i] = stk.top();
        }
        stk.push(i);
    }

    // 做一个特殊前缀后缀和，来预处理单点贡献
    vector<ll> pre(n, -1), suf(n, n);
    for (int i = 0; i < n; i++) {
        pre[i] = 1ll * a[i] * (i - Lless[i]) + (Lless[i] == -1 ? 0 : pre[Lless[i]]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = 1ll * a[i] * (Rless[i] - i) + (Rless[i] == n ? 0 : suf[Rless[i]]);
    }

    // ST表
    RMQidx<int> rmq(a);

    // 莫队
    auto Mol = [&](int l, int r) {
        int p = rmq(l, r + 1);
        return suf[l] - suf[p] + 1ll * (r - p + 1) * a[p];
    };
    auto Mor = [&](int l, int r) {
        int p = rmq(l, r + 1);
        return pre[r] - pre[p] + 1ll * (p - l + 1) * a[p];
    };

    int L = 0, R = -1;
    vector<ll> ans(m);
    ll now = 0;
    for (auto [l, r, id] : q) {
        while (L > l) {
            L--;
            now += Mol(L, R);
        }
        while (R < r) {
            R++;
            now += Mor(L, R);
        }
        while (L < l) {
            now -= Mol(L, R);
            L++;
        }
        while (R > r) {
            now -= Mor(L, R);
            R--;
        }
        ans[id] = now;
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}