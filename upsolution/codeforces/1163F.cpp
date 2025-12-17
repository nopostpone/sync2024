#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

using P = pair<i64, int>;
using Heap = priority_queue<P, vector<P>, greater<>>;

constexpr i64 inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> edges(m);
    vector<vector<tuple<int, int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {u, v};
        adj[u].emplace_back(v, w, i);
        adj[v].emplace_back(u, w, i);
    }
    auto work = [&adj](int st, vector<i64> &f) {
        Heap pq;

        pq.emplace(0, st);
        f[st] = 0;
        while (not pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();

            if (d > f[x]) {
                continue;
            }
            for (auto [y, w, _] : adj[x]) {
                if (i64 cur = f[x] + w; cur < f[y]) {
                    f[y] = cur;
                    pq.emplace(f[y], y);
                }
            }
        }
    };

    vector<i64> f0(n, inf), fn(n, inf);

    work(0, f0);
    work(n - 1, fn);

    vector<int> pEdge(n, -1);
    vector<vector<int>> nadj(n);
    {
        vector<bool> vis(n);
        vis[n - 1] = true;

        queue<int> q;
        q.push(n - 1);
        while (not q.empty()) {
            int x = q.front();
            q.pop();

            for (auto [y, w, i] : adj[x]) {
                if (fn[x] + w == fn[y] and not vis[y]) {
                    vis[y] = true;
                    q.push(y);
                    pEdge[y] = i;
                    nadj[x].push_back(y);
                }
            }
        }
    }

    vector<int> in(n), out(n);
    {
        int cur = 0;
        [&](this auto &&self, int x) -> void {
            in[x] = cur++;
            for (auto y : nadj[x]) {
                self(y);
            }
            out[x] = cur;
        }(n - 1);
    }
    auto isAnc = [&](int par, int son) {
        return in[par] <= in[son] and in[son] < out[par];
    };

    vector<i64> res(n, inf); // 1 -> n 且不经过 x -> parent_x 的最短路
    vector<Heap> vec(n);

    [&](this auto &&self, int x) -> void {
        for (auto [y, w, i] : adj[x]) {
            if (i == pEdge[x]) {
                continue;
            }
            vec[x].emplace(f0[x] + w + fn[y], y);
        }
        for (auto y : nadj[x]) {
            self(y);
            // 合并
            if (vec[x].size() < vec[y].size()) {
                swap(vec[x], vec[y]);
            }
            while (not vec[y].empty()) {
                vec[x].push(vec[y].top());
                vec[y].pop();
            }
        }
        while (not vec[x].empty()) {
            auto [d, y] = vec[x].top();
            // 如果 x 是 y 的祖先，那么 fn[y] 经过 x，要推掉
            if (isAnc(x, y)) {
                vec[x].pop();
            } else {
                res[x] = d;
                break;
            }
        }
    }(n - 1);

    while (q--) {
        int i, w;
        cin >> i >> w;
        i--;

        auto [u, v] = edges[i];
        if (fn[u] < fn[v]) {
            swap(u, v);
        }
        i64 ans = min(f0[u] + w + fn[v], f0[v] + w + fn[u]);

        if (pEdge[u] != i or not isAnc(u, 0)) {
            ans = min(ans, f0[n - 1]);
        } else {
            ans = min(ans, res[u]);
        }
        cout << ans << "\n";
    }

    return 0;
}