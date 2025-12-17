{
    int n;
    std::vector<std::vector<int>> adj(n);
    // ...
    std::vector<int> siz(n);
    [&](this auto &&self, int x, int p) -> void {
        if (p != -1) {
            adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
        }
        siz[x] = 1;
        // &y
        for (auto &y : adj[x]) {
            self(y, x);
            siz[x] += siz[y];
            if (siz[y] > siz[adj[x][0]]) {
                swap(adj[x][0], y);
            }
        }
    } (0, -1);

    auto addv = [&](int color, int t) {
        // freq[color] += t
    };
    auto add = [&](auto &&self, int x, int t) -> void {
        // addv(color[x], t);
        for (auto y : adj[x]) {
            self(self, y, t);
        }
    };
    auto dfs = [&](auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y != adj[x][0]) {
                self(self, y);
                add(add, y, -1);
            }
        }
        if (not adj[x].empty()) {
            self(self, adj[x][0]);
            for (auto y : adj[x]) {
                if (y != adj[x][0]) {
                    add(add, y, 1);
                }
            }
        }
        addv(color[x], 1);
        // ans[x] = ?
    };
    // dfs(0);
}