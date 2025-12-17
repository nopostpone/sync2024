#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

template <class T, T e, auto func>
struct SparseTable {
    int n;
    std::vector<std::vector<T>> a;
    SparseTable(const std::vector<T> &v = {}) {
        init(v);
    }
    void init(const std::vector<T> &v) {
        n = v.size();
        if (n == 0) {
            return;
        }
        const int m = std::__lg(n);
        a.assign(m + 1, std::vector<T>(n));
        a[0] = v;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i + (2 << j) <= n; i++) {
                a[j + 1][i] = func(a[j][i], a[j][i + (1 << j)]);
            }
        }
    }
    T operator()(int l, int r) const {
        if (l >= r) {
            return e;
        } else {
            const int k = std::__lg(r - l);
            return func(a[k][l], a[k][r - (1 << k)]);
        }
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<tuple<int, int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, c, l;
        cin >> u >> v >> c >> l;
        u--;
        v--;
        c--;

        adj[u].emplace_back(v, c, l);
        adj[v].emplace_back(u, c, l);
    }

    vector<int> a(k), b(k);
    vector<vector<int>> vec(m);
    for (int i = 0; i < k; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        vec[a[i]].emplace_back(i);
    }

    vector<SparseTable<pair<int, int>, pair(0, -1), [](auto i, auto j) {
        return max(i, j);
    }>> rmq(m);

    for (int i = 0; i < m; i++) {
        vector<pair<int, int>> t;
        for (auto x : vec[i]) {
            t.emplace_back(b[x], x);
        }
        rmq[i].init(t);
    }

    vector<pair<int, int>> f(n, pair(k, 0));

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
    auto upd = [&](int x, int cur, int len) {
        if (pair(cur, len) < f[x]) {
            f[x] = pair(cur, len);
            q.emplace(cur, len, x);
        }
    };
    upd(0, 0, 0);

    while (not q.empty()) {
        auto [cur, len, x] = q.top();
        q.pop();

        if (pair(cur, len) > f[x]) {
            continue;
        }

        for (auto [y, c, l] : adj[x]) {
            if (c == a[cur] and len + l <= b[cur]) {
                upd(y, cur, len + l);
            } else {
                int s = upper_bound(vec[c].begin(), vec[c].end(), cur) - vec[c].begin();
                int lo = s;
                int hi = vec[c].size();
                while (lo < hi) {
                    int x = (lo + hi) / 2;
                    if (rmq[c](s, x + 1).first >= l) {
                        hi = x;
                    } else {
                        lo = x + 1;
                    }
                }

                if (lo < vec[c].size()) {
                    int nxt = vec[c][lo];
                    upd(y, nxt, l);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (f[i].first < k);
    }
    cout << "\n";
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