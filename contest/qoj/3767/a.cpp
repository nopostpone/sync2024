#include <bits/stdc++.h>

using i64 = long long;

namespace rgs = std::ranges;

constexpr int N = 50000;
using B = std::bitset<N>;

void solve()  {
    int n, m;
    std::cin >> n >> m;

    auto encode = [&](int i, int j) {
        return i * m + j;
    };
    auto decode = [&](int x) {
        return std::pair(x / m, x % m);
    };

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::vector<std::vector<int>> adj(n * m);
    std::vector<B> f(n * m);

    std::vector<int> deg(n * m);

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {

            int u = encode(x, y);

            int nx = x, ny = y;
            if (s[x][y] == 'L') {
                while (--ny >= 0) {
                    int v = encode(nx, ny);
                    f[u].set(v);
                    adj[v].push_back(u);
                    deg[u]++;
                    if (s[nx][ny] == s[x][y]) {
                        break;
                    }
                }
            } else if (s[x][y] == 'R') {
                while (++ny < m) {
                    int v = encode(nx, ny);
                    f[u].set(v);
                    adj[v].push_back(u);
                    deg[u]++;
                    if (s[nx][ny] == s[x][y]) {
                        break;
                    }
                }
            } else if (s[x][y] == 'U') {
                while (--nx >= 0) {
                    int v = encode(nx, ny);
                    f[u].set(v);
                    adj[v].push_back(u);
                    deg[u]++;
                    if (s[nx][ny] == s[x][y]) {
                        break;
                    }
                }
            } else {
                while (++nx < n) {
                    int v = encode(nx, ny);
                    f[u].set(v);
                    adj[v].push_back(u);
                    deg[u]++;
                    if (s[nx][ny] == s[x][y]) {
                        break;
                    }
                }
            }
        }
    }

    std::vector<int> cnt(n * m);
    {
        std::queue<int> q;
        for (int i = 0; i < n * m; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        while (not q.empty()) {
            int x = q.front();
            q.pop();
            cnt[x]++;

            for (auto y : adj[x]) {
                deg[y]--;
                if (deg[y] == 0) {
                    q.push(y);
                }
                f[y] |= f[x];
            }
        }
    }

    for (int i = 0; i < n * m; i++) {
        int ans = f[i].count() + 1;
        if (cnt[i] == 0) {
            ans = -1;
        }
        std::cout << ans << " \n"[(i + 1) % m == 0];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}

/*
2
4 3
RRD
DUL
RDD
RRR
1 2
LR
*/