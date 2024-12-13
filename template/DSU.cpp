/// @brief 并查集
struct DSU {
    vector<int> f, siz;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int fa, int son) {
        fa = find(fa);
        son = find(son);
        if (fa == son) {
            return false;
        }
        siz[fa] += siz[son];
        f[son] = fa;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};