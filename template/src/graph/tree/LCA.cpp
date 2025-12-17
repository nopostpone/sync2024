// Binary Lifting O(n log n) - O(log n)
{
    const int logn = std::__lg(n);

    std::vector<int> dep(n);
    std::vector p(logn + 1, std::vector<int>(n));
    auto dfs = [&](auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[0][x]) {
                continue;
            }
            p[0][y] = x;
            dep[y] = dep[x] + 1;
            self(self, y);
        }
    };

    p[0][s] = s;
    dfs(dfs, s);

    for (int j = 0; j < logn; j++) {
        for (int i = 0; i < n; i++) {
            p[j + 1][i] = p[j][p[j][i]];
        }
    }

    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) {
            std::swap(x, y);
        }
        while (dep[x] > dep[y]) {
            x = p[std::__lg(dep[x] - dep[y])][x];
        }
        if (x == y) {
            return x;
        }
        for (int i = std::__lg(dep[x]); i >= 0; i--) {
            if (p[i][x] != p[i][y]) {
                x = p[i][x];
                y = p[i][y];
            }
        }
        return p[0][x];
    };
}