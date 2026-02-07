#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

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
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dep(n), siz(n), in(n), out(n), seq(n);
    vector<int> g(n);

    int cur = 0;
    [&](this auto &&self, int x, int p) -> void {
        if (p != -1) {
            adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
        }
        siz[x] = 1;

        in[x] = cur;
        seq[cur] = x;
        cur++;
        g[x] = dep[x];

        for (auto &y : adj[x]) {
            dep[y] = dep[x] + 1;
            self(y, x);
            g[x] = max(g[x], g[y]);
            siz[x] += siz[y];

            if (siz[y] > siz[adj[x][0]]) {
                swap(y, adj[x][0]);
            }
        }
        out[x] = cur;
    } (0, -1);

    for (int i = 0; i < n; i++) {
        g[i] -= dep[i];
    }
    
    vector<int> h(n);
    {
        vector<int> pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = max(pre[i], dep[seq[i]]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = max(suf[i + 1], dep[seq[i]]);
        }
        for (int i = 0; i < n; i++) {
            h[i] = max(pre[in[i]], suf[out[i]]);
        }
    }

    Fenwick<i64> weight(n);
    Fenwick<int> cnt(n);

    for (int i = 0; i < n; i++) {
        cnt.add(dep[i], 1);
        weight.add(dep[i], dep[i] + 1);
    }

    auto add = [&](this auto &&self, int x, int t) -> void {
        cnt.add(dep[x], -t);
        weight.add(dep[x], -t * (dep[x] + 1));
        for (auto y : adj[x]) {
            self(y, t);
        }
    };

    i64 ans = 0;
    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y != adj[x][0]) {
                self(y);
                add(y, -1);
            }
        }
        if (not adj[x].empty()) {
            self(adj[x][0]);
            for (auto y : adj[x]) {
                if (y != adj[x][0]) {
                    add(y, 1);
                }
            }
        }
        
        cnt.add(dep[x], -1);
        weight.add(dep[x], -(dep[x] + 1));
        int bound = max(0, h[x] - g[x]);
        
        ans += i64(n - siz[x]) * h[x];
        ans += weight.rangeSum(bound, n);
        ans -= i64(h[x] - g[x]) * cnt.rangeSum(bound, n);
    } (0);
    
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