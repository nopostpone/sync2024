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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> in(n), dep(n), siz(n);
    vector<array<int, 19>> p(n);
    vector<i64> pre(n);
    pre[0] = a[0] == 1 ? 0 : a[0];
    int ord = 0;
    auto dfs = [&](auto &&self, int x) -> void {
        in[x] = ord++;
        siz[x] = 1;
        for (int i = 1; i <= __lg(n); i++) {
            p[x][i] = p[p[x][i - 1]][i - 1];
        }
        for (auto y : adj[x]) {
            if (y == p[x][0]) {
                continue;
            }
            if (a[y] == 1) {
                pre[y] = pre[x];
            } else {
                pre[y] = pre[x] + a[y];
            }
            dep[y] = dep[x] + 1;
            p[y][0] = x;
            self(self, y);
            siz[x] += siz[y];
        }
    };
    dfs(dfs, 0);

    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) {
            swap(u, v);
        }
        while (dep[u] > dep[v]) {
            u = p[u][__lg(dep[u] - dep[v])];
        }
        if (u == v) {
            return u;
        }

        for (int i = __lg(dep[u]); i >= 0; i--) {
            if (p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    };

    Fenwick<i64> fen(n + 1);
    auto calc = [&](int u) {
        return pre[u] + fen.sum(in[u] + 1);
    };

    while (q--) {
        int o;
        cin >> o;
        if (o == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            int anc = lca(x, y);
            int dis = dep[x] + dep[y] - 2 * dep[anc];
            if (dis > 24) {
                i64 s = calc(x) + calc(y) - 2 * calc(anc) + (a[anc] > 1 ? a[anc] : 0);

                cout << (s <= 24) << "\n";
            } else {
                vector<int> seqx, seqy;
                for (int i = x; i != anc; i = p[i][0]) {
                    seqx.push_back(i);
                }
                for (int i = y; i != anc; i = p[i][0]) {
                    seqy.push_back(i);
                }
                seqy.push_back(anc);
                reverse(seqy.begin(), seqy.end());
                array<bool, 25> dp{};
                dp[0] = true;
                for (auto u : seqx) {
                    array<bool, 25> ndp{};
                    for (int i = 0; i <= 24; i++) {
                        if (i + a[u] <= 24) {
                            ndp[i + a[u]] |= dp[i];
                        }
                        if (i and (i64) i * a[u] <= 24) {
                            ndp[i * a[u]] |= dp[i];
                        }
                    }
                    dp = move(ndp);
                }

                for (auto u : seqy) {
                    array<bool, 25> ndp{};
                    for (int i = 0; i <= 24; i++) {
                        if (i + a[u] <= 24) {
                            ndp[i + a[u]] |= dp[i];
                        }
                        if (i and (i64) i * a[u] <= 24) {
                            ndp[i * a[u]] |= dp[i];
                        }
                    }
                    dp = move(ndp);
                }
                cout << dp[24] << "\n";
            }
        } else {
            int x, d;
            cin >> x >> d;
            x--;

            int i = in[x];
            if (a[x] > 1) {
                fen.add(i, -a[x]);
                fen.add(i + siz[x], a[x]);
            }
            if (d > 1) {
                fen.add(i, d);
                fen.add(i + siz[x], -d);
            }

            a[x] = d;
        }
    }

    return 0;
}