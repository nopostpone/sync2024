#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(m), b(m), s(m), t(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> s[i] >> t[i];
        a[i]--;
        b[i]--;
    }

    vector<map<int, int>> bus(n);
    for (int i = 0; i < m; i++) {
        bus[a[i]][s[i]] = i;
    }

    auto next = [&](int x, int t) {
        auto it = bus[x].lower_bound(t);
        if (it == bus[x].end()) {
            return -1;
        }
        return it->second;
    };

    vector<int> nxt(m, -1);
    for (int i = 0; i < m; i++) {
        nxt[i] = next(b[i], t[i]);
    }

    vector<int> ord;
    for (int i = 0; i < m; i++) {
        if (nxt[i] != -1) {
            ord.push_back(i);
        }
    }
    ranges::sort(ord, [&](int i, int j) {
        return s[nxt[i]] < s[nxt[j]];
    });

    vector<int> ans(q);
    vector<array<int, 4>> ask(q);

    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        y--;
        ask[i] = {z, x, y, i};
    }
    ranges::sort(ask);

    DSU dsu(m);

    int i = 0;
    for (auto [z, x, y, k] : ask) {
        while (i < ord.size() and s[nxt[ord[i]]] < z) {
            dsu.merge(nxt[ord[i]], ord[i]);
            i++;
        }

        int j = next(y, x);
        if (j == -1 or s[j] >= z) {
            ans[k] = y;
        } else {
            j = dsu.find(j);
            if (z > t[j]) {
                ans[k] = b[j];
            } else {
                ans[k] = n + j;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (ans[i] < n) {
            cout << ans[i] + 1 << "\n";
        } else {
            cout << a[ans[i] - n] + 1 << " " << b[ans[i] - n] + 1 << "\n";
        }
    }

    return 0;
}
