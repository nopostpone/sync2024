#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) { init(n); }

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

    string s;
    cin >> s;

    int n = s.size();
    int sqrtn = std::sqrt(n);

    vector dsu(sqrtn, DSU(n + 1));

    int q;
    cin >> q;

    vector<array<int, 4>> que(q);
    for (int i = 0; i < q; i++) {
        int st, a, k;
        char c;
        cin >> st >> a >> k >> c;
        st--;

        que[q - i - 1] = {st, a, k, c - 'a'};
    }

    vector<bool> vis(n);
    for (auto [i, a, k, c] : que) {
        if (a >= sqrtn) {
            for (int j = 0; j <= k; j++) {
                int x = i + j * a;
                if (not vis[x]) {
                    vis[x] = true;
                    s[x] = c + 'a';
                }
            }
            continue;
        }

        int cur = i;
        while ((cur - i) / a <= k and cur < n) {
            if (not vis[cur]) {
                vis[cur] = true;
                s[cur] = c + 'a';
            }
            dsu[a].merge(min(n, cur + a), cur);
            cur = dsu[a].find(cur);
        }
    }
    cout << s << "\n";

    return 0;
}