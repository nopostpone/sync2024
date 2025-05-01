/// @brief 可撤销并查集
struct DSU {
    std::vector<int> siz, f;
    std::vector<std::pair<int *, int>> his;
 
    DSU () {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        his.emplace_back(&siz[x], siz[x]);
        siz[x] += siz[y];
        his.emplace_back(&f[y], f[y]);
        f[y] = x;
        return true;
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x];
        }
        return x;
    }
    int same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return siz[find(x)];
    }
    void undo(int x) {
        while (int(his.size()) > x) {
            *his.back().first = his.back().second;
            his.pop_back();
        }
    }
};