#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int B = 70;
constexpr int S = 4300;

void solve() {
    int n, k, s, q;
    cin >> n >> k >> s >> q;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dep(n), p(n);
    p[0] = -1;
    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[x]) {
                continue;
            }
            p[y] = x;
            dep[y] = dep[x] + 1;
            self(y);
        }
    } (0);

    vector<vector<int>> vec(k); // 每个颜色有哪些节点
    for (int i = 0; i < s; i++) {
        int v, x;
        cin >> v >> x;
        v--;
        x--;
        vec[x].push_back(v);
    }

    int tot = 0;

    vector<vector<int>> seg(s); // 记录同色连通块
    vector<vector<int>> col(n); // 记录这个点存放的连通块的编号

    vector<int> vis(n, -1);
    for (int x = 0; x < k; x++) {
        ranges::sort(vec[x], [&](int i, int j) {
            return dep[i] < dep[j];
        });

        // 由于我们以深度进行了升序，从浅到深遍历，处理出该颜色所有连通块
        for (auto i : vec[x]) {
            if (p[i] != -1 and vis[p[i]] != -1) {
                vis[i] = vis[p[i]];
            } else {
                vis[i] = tot++;
            }

            col[i].push_back(vis[i]);
            seg[vis[i]].push_back(i);
        }
        for (auto i : vec[x]) {
            vis[i] = -1;
        }
    }
    for (int i = 0; i < s; i++) {
        ranges::sort(seg[i]);
    }

    vector<bitset<S>> f(n); // f[x] 表示点 x 被哪些连通块包含
    for (int i = 0, cur = 0; i < s; i++) {
        if (seg[i].size() > B) {
            for (auto x : seg[i]) {
                f[x].set(cur);
            }
            cur++;
        }
    }

    vector<vector<pair<int, int>>> ask(n);
    vector<int> ans(q);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x < y) {
            swap(x, y);
        }
        ask[x].emplace_back(y, i);
        ans[i] += (f[x] & f[y]).count(); // 先加上大线段的贡献
    }

    vector<int> tem(n);

    // 对于每个 x，暴力遍历所有小连通块中，小于它的 y
    // 由于我们之前离线了询问 {u, v}，其中 u > v
    // 此时就可以遍历所有 u = x 的询问，加上 y = v 的贡献
    for (int x = 0; x < n; x++) {
        for (auto c : col[x]) {
            if (seg[c].size() > B) {
                continue;
            }

            for (auto y : seg[c]) {
                if (y > x) {
                    break;
                }
                tem[y]++;
            }
        }
        for (auto [y, i] : ask[x]) {
            ans[i] += tem[y];
        }
        for (auto c : col[x]) {
            if (seg[c].size() > B) {
                continue;
            }

            for (auto y : seg[c]) {
                if (y > x) {
                    break;
                }
                tem[y]--;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << " \n"[i == q - 1];
    }
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
