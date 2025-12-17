#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int query(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ord(n - 1);
    iota(ord.begin(), ord.end(), 1);
    ranges::sort(ord, [&](int i, int j) {
        return query(0, i, j) == 1;
    });

    vector<vector<int>> adj(n);
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    set<pair<int, int>> vis;
    vector<int> p(n), siz(n);

    vector<int> vec;
    auto dfs = [&](auto &&self, int x) -> void {
        vec.push_back(x);
        siz[x] = 1;
        for (auto y : adj[x]) {
            if (y == p[x] or vis.contains(minmax(x, y))) {
                continue;
            }
            p[y] = x;
            self(self, y);
            siz[x] += siz[y];
        }
    };
    auto Find = [&](auto &&self, int x, int newv) -> int {
        p[x] = -1;
        vec.clear();

        dfs(dfs, x);
        if (siz[x] == 1) {
            return x;
        }
        int u = -1;
        int res = n + 1;
        for (auto y : vec) {
            int nres = max(siz[y], siz[x] - siz[y]);
            if (nres < res) {
                res = nres;
                u = y;
            }
        }

        vis.insert(minmax(u, p[u]));
        if (query(newv, u, p[u]) == 1) {
            return self(self, u, newv);
        } else {
            return self(self, p[u], newv);
        }
    };

    for (auto x : ord) {
        int y = Find(Find, 0, x);
        addEdge(x, y);
        vis.clear();
    }

    cout << "!\n";
    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            if (j > i) {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }

    return 0;
}
