#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    int tot = n;
    vector<vector<int>> adj(2 * n);
    auto addEdge = [&](int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    };
    
    Fenwick<i64> fen(n - 1);
    vector<int> f(2 * n), g(n - 1);
    for (int i = 0; i < n; i++) {
        f[i] = a[i];
    }
    {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        
        while (q.size() > 1) {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();

            f[tot] = min(f[x], f[y]);
            g[tot - n] = max(f[x], f[y]);
            fen.add(tot - n, g[tot - n]);
            
            addEdge(tot, x);
            addEdge(tot, y);
            q.push(tot);
            
            tot++;
        }
    }
    
    auto dfs = [&](this auto &&self, int x) -> void {
        if (x == tot - 1) {
            return;
        }
        int p = adj[x].back();

        int u = adj[p][0];
        int v = adj[p][1];
        
        fen.add(p - n, -g[p - n]);
        f[p] = min(f[u], f[v]);
        g[p - n] = max(f[u], f[v]);
        fen.add(p - n, g[p - n]);
        
        self(p);
    };

    for (int _ = 0; _ < m; _++) {
        char o;
        cin >> o;

        if (o == 'A') {
            int l, r;
            cin >> l >> r;
            l--;

            cout << fen.rangeSum(l, r) << "\n";

        } else {
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            swap(f[x], f[y]);
            dfs(x);
            dfs(y);
        }
    }
}

/*
5 6
4 3 1 2 5
A 3 4
C 1 2
A 3 4
A 2 4
C 3 5
A 1 3
*/

/*
5 2
4 3 1 2 5
A 3 4
A 1 1
*/