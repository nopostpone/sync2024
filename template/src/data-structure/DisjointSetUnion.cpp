struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
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
    // merge y to x
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

// Weighted DSU
// Amortized O(\alpha(n)), worst-case O(log n)
template <class T>
struct DSU {
    std::vector<int> f, siz;
    std::vector<T> w;

    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        w.assign(n, T());
    }
    int find(int x) {
        if (x != f[x]) {
            int y = find(f[x]);
            w[x] += w[f[x]];
            f[x] = y;
        }
        return f[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    // 
    bool merge(int x, int y, T k) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return w[x] - w[y] == k;
        }
        // union by rank
        if (siz[rx] < siz[ry]) {
            f[rx] = ry;
            w[rx] = k - w[x] + w[y];
            siz[ry] += siz[rx];
        } else {
            f[ry] = rx;
            w[ry] = -k + w[x] - w[y];
            siz[rx] += siz[ry];
        }
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};


// DSU with Rollback
struct DSU {
    std::vector<std::pair<int *, int>> his;
    std::vector<int> f, siz;

    DSU () {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    void set(int &a, int b) {
        his.emplace_back(&a, a); 
        a = b;
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x];
        }
        return x;
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
        set(siz[x], siz[x] + siz[y]);
        set(f[y], x);
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int cur() {
        return his.size();
    }
    void rollback(int t) {
        while (his.size() > t) {
            auto [ptr, old] = his.back();
            *ptr = old;
            his.pop_back();
        }
    }
};