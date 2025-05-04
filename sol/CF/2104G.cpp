#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct DSU {
    std::vector<std::pair<int &, int>> his;
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
        his.emplace_back(a, a);
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
            auto [x, y] = his.back();
            x = y;
            his.pop_back();
        }
    }
};

template <class T>
T power(int a, T b, T p) {
    T res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        g[i]--;
    }

    vector<vector<array<int, 2>>> info(4 << __lg(q));
    auto addEdge = [&](int x, int y, int u, int v) {
        const array<int, 2> e = {u, v};

        auto work = [&](this auto &&self, int p, int l, int r) {
            if (l >= y or r <= x) {
                return;
            }
            if (l >= x and r <= y) {
                info[p].push_back(e);
                return;
            }
            int m = (l + r) / 2;
            self(2 * p, l, m);
            self(2 * p + 1, m, r);
        };
        work(1, 0, q);
    };

    vector<int> lst(n), k(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y >> k[i];
        x--;
        y--;
        k[i] %= 3;

        addEdge(lst[x], i, x, g[x]);
        g[x] = y;
        lst[x] = i;
    }
    for (int x = 0; x < n; x++) {
        addEdge(lst[x], q, x, g[x]);
    }

    DSU dsu(2 * n);
    int tot = n, odd = 0;
    auto work = [&](this auto &&self, int p, int l, int r) -> void {
        int ori = dsu.cur();
        int cnt = 0;

        auto [ht, ho] = make_pair(tot, odd);
        
        for (auto [u, v] : info[p]) {
            if (dsu.same(u, v)) {
                cnt++;
            } else {
                if (dsu.merge(u, v + n)) {
                    tot--;
                }
                dsu.merge(v, u + n);
            }
        }
        odd += cnt;

        if (r - l == 1) {
            int ans = power(k[l], n - (tot - odd), 3);
            cout << ans << "\n";
        } else {
            int m = (l + r) / 2;
            self(2 * p, l, m);
            self(2 * p + 1, m, r);
        }

        dsu.rollback(ori);
        tie(tot, odd) = make_pair(ht, ho);
    };

    work(1, 0, q);

    return 0;
}

