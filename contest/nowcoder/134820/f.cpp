// #include <bits/stdc++.h>

// using u32 = unsigned;
// using i64 = long long;
// using u64 = unsigned long long;

// using i128 = __int128;
// using u128 = unsigned __int128;

// struct DSU {
//     std::vector<std::pair<int *, int>> his;
//     std::vector<int> f, siz, weight;

//     DSU () {}
//     DSU(int n) {
//         init(n);
//     }
//     void init(int n) {
//         f.resize(n);
//         std::iota(f.begin(), f.end(), 0);
//         siz.assign(n, 1);
//         weight.assign(n, 0);
//     }
//     void set(int &a, int b) {
//         his.emplace_back(&a, a); 
//         a = b;
//     }
//     int find(int x) {
//         while (x != f[x]) {
//             x = f[x];
//         }
//         return x;
//     }
//     bool merge(int x, int y) {
//         x = find(x);
//         y = find(y);
//         if (x == y) {
//             return false;
//         }
//         if (siz[x] < siz[y]) {
//             std::swap(x, y);
//         }
//         set(weight[x], weight[x] + weight[y]);
//         set(siz[x], siz[x] + siz[y]);
//         set(f[y], x);
//         return true;
//     }
//     void addWeight(int x, int val) {
//         x = find(x);
//         set(weight[x], weight[x] + val);
//     }
//     int getWeight(int x) {
//         return weight[find(x)];
//     }
//     bool same(int x, int y) {
//         return find(x) == find(y);
//     }
//     int cur() {
//         return his.size();
//     }
//     void rollback(int t) {
//         while (his.size() > t) {
//             auto [ptr, old_val] = his.back();
//             *ptr = old_val;
//             his.pop_back();
//         }
//     }
// };

// constexpr int dx[] {0, 1};
// constexpr int dy[] {1, 0};

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int n, m, q;
//     std::cin >> n >> m >> q;

//     const int outer = n * m;

//     std::vector<std::vector<std::pair<int, int>>> vec(n * m);
//     for (int x = 0; x < n; x++) {
//         std::string s;
//         std::cin >> s;

//         for (int y = 0; y < m; y++) {
//             int u = x * m + y;
//             vec[u].emplace_back(0, s[y] - '0');
//         }
//     }

//     for (int i = 0; i < q; i++) {
//         int x, y, c;
//         std::cin >> x >> y >> c;
//         x--;
//         y--;

//         vec[x * m + y].emplace_back(i + 1, c);
//     }
//     for (auto &v : vec) {
//         v.emplace_back(q + 1, 0);
//     }

//     auto solve = [&](int A) {
//         int B = 3 - A;

//         std::vector<std::vector<std::array<int, 2>>> edgeInfo(4 * (q + 1));
//         auto addEdge = [&](int u, int v, int x, int y) -> void {
//             auto dfs = [u, v, x, y, &edgeInfo](this auto &&self, int p, int l, int r) -> void {
//                 if (l >= y or r <= x) {
//                     return;
//                 }
//                 if (l >= x and r <= y) {
//                     edgeInfo[p].push_back({u, v});
//                     return;
//                 }
//                 int m = (l + r) / 2;
//                 self(2 * p, l, m);
//                 self(2 * p + 1, m, r);
//             };
//             dfs(1, 0, q + 1);
//         };

//         std::vector<std::vector<std::array<int, 2>>> weightInfo(4 * (q + 1));
//         auto addWeight = [&](int u, int val, int x, int y) -> void {
//             auto dfs = [u, val, x, y, &weightInfo](this auto &&self, int p, int l, int r) -> void {
//                 if (l >= y or r <= x) {
//                     return;
//                 }
//                 if (l >= x and r <= y) {
//                     weightInfo[p].push_back({u, val});
//                     return;
//                 }
//                 int m = (l + r) / 2;
//                 self(2 * p, l, m);
//                 self(2 * p + 1, m, r);
//             };
//             dfs(1, 0, q + 1);
//         };

//         std::vector<int> tot(q + 2);
//         for (int x = 0; x < n; x++) {
//             for (int y = 0; y < m; y++) {
//                 int u = x * m + y;
//                 for (int dir = 0; dir < 2; dir++) {
//                     int nx = x + dx[dir];
//                     int ny = y + dy[dir];
//                     if (nx >= n or ny >= m) {
//                         continue;
//                     }

//                     int v = nx * m + ny;

//                     for (int i = 0, j = 0; i + 1 < vec[u].size() and j + 1 < vec[v].size();) {
//                         auto [ul, uc] = vec[u][i];
//                         auto [vl, vc] = vec[v][j];
//                         int ur = vec[u][i + 1].first;
//                         int vr = vec[v][j + 1].first;

//                         int l = std::max(ul, vl);
//                         int r = std::min(ur, vr);
//                         if (l < r and uc != A and vc != A) {
//                             addEdge(u, v, l, r);
//                         }
//                         if (ur < vr) {
//                             i++;
//                         } else if (ur > vr) {
//                             j++;
//                         } else {
//                             i++;
//                             j++;
//                         }
//                     }
//                 }

//                 for (int i = 0; i + 1 < vec[u].size(); i++) {
//                     int l = vec[u][i].first;
//                     int r = vec[u][i + 1].first;
//                     int c = vec[u][i].second;
//                     assert(l < r);
//                     if (c == B) {
//                         tot[l] += 1;
//                         tot[r] -= 1;
//                         addWeight(u, 1, l, r);
//                     }
//                     if ((x == 0 or y == 0 or x == n - 1 or y == m - 1) and c != A) {
//                         addEdge(u, outer, l, r);
//                     }
//                 }
//             }
//         }
//         for (int i = 0; i < q + 1; i++) {
//             tot[i + 1] += tot[i];
//         }

//         DSU dsu(n * m + 1);
//         std::vector<int> ans(q + 1);

//         [&](this auto &&self, int p, int l, int r) -> void {
//             int cur = dsu.cur();

//             for (auto [u, v] : edgeInfo[p]) {
//                 dsu.merge(u, v);
//             }
//             for (auto [x, val] : weightInfo[p]) {
//                 dsu.addWeight(x, val);
//             }
//             if (r - l == 1) {
//                 ans[l] = tot[l] - dsu.getWeight(outer);
//             } else {
//                 int m = std::midpoint(l, r);
//                 self(p * 2, l, m);
//                 self(p * 2 + 1, m, r);
//             }

//             dsu.rollback(cur);
//         } (1, 0, q + 1);

//         return ans;
//     };
//     auto ans1 = solve(1);
//     auto ans2 = solve(2);

//     for (int i = 0; i < q + 1; i++) {
//         if (ans1[i] > ans2[i]) {
//             std::cout << "Black\n";
//         } else if (ans1[i] < ans2[i]) {
//             std::cout << "White\n";
//         } else {
//             std::cout << "Draw\n";
//         }
//     }
// }

// 以上代码在牛客的 clang++ 18 不过编！

#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct DSU {
    std::vector<std::pair<int *, int>> his;
    std::vector<int> f, siz, weight;

    DSU () {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        weight.assign(n, 0);
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
        set(weight[x], weight[x] + weight[y]);
        set(siz[x], siz[x] + siz[y]);
        set(f[y], x);
        return true;
    }
    void addWeight(int x, int val) {
        x = find(x);
        set(weight[x], weight[x] + val);
    }
    int getWeight(int x) {
        return weight[find(x)];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int cur() {
        return his.size();
    }
    void rollback(int t) {
        while (his.size() > t) {
            auto [ptr, old_val] = his.back();
            *ptr = old_val;
            his.pop_back();
        }
    }
};

constexpr int dx[] {0, 1};
constexpr int dy[] {1, 0};

std::vector<int> solve(int A, int n, int m, int q, const std::vector<std::vector<std::pair<int, int>>>& vec) {
    int B = 3 - A;
    const int outer = n * m;

    std::vector<std::vector<std::array<int, 2>>> edgeInfo(4 * (q + 1));
    std::vector<std::vector<std::array<int, 2>>> weightInfo(4 * (q + 1));

    auto addEdge = [&](auto& self, int p, int l, int r, int ql, int qr, int u, int v) -> void {
        if (l >= qr or r <= ql) return;
        if (l >= ql and r <= qr) {
            edgeInfo[p].push_back({u, v});
            return;
        }
        int mid = l + (r - l) / 2;
        self(self, 2 * p, l, mid, ql, qr, u, v);
        self(self, 2 * p + 1, mid, r, ql, qr, u, v);
    };

    auto addWeight = [&](auto& self, int p, int l, int r, int ql, int qr, int u, int val) -> void {
        if (l >= qr or r <= ql) return;
        if (l >= ql and r <= qr) {
            weightInfo[p].push_back({u, val});
            return;
        }
        int mid = l + (r - l) / 2;
        self(self, 2 * p, l, mid, ql, qr, u, val);
        self(self, 2 * p + 1, mid, r, ql, qr, u, val);
    };

    auto insertEdge = [&](int u, int v, int l, int r) {
        addEdge(addEdge, 1, 0, q + 1, l, r, u, v);
    };
    auto insertWeight = [&](int u, int val, int l, int r) {
        addWeight(addWeight, 1, 0, q + 1, l, r, u, val);
    };

    std::vector<int> tot(q + 2, 0);
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            int u = x * m + y;
            for (int dir = 0; dir < 2; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= n or ny >= m) {
                    continue;
                }

                int v = nx * m + ny;

                for (int i = 0, j = 0; i + 1 < vec[u].size() and j + 1 < vec[v].size();) {
                    auto [ul, uc] = vec[u][i];
                    auto [vl, vc] = vec[v][j];
                    int ur = vec[u][i + 1].first;
                    int vr = vec[v][j + 1].first;

                    int l = std::max(ul, vl);
                    int r = std::min(ur, vr);
                    if (l < r and uc != A and vc != A) {
                        insertEdge(u, v, l, r);
                    }
                    
                    if (ur < vr) {
                        i++;
                    } else if (ur > vr) {
                        j++;
                    } else {
                        i++;
                        j++;
                    }
                }
            }

            for (int i = 0; i + 1 < vec[u].size(); i++) {
                int l = vec[u][i].first;
                int r = vec[u][i + 1].first;
                int c = vec[u][i].second;
                assert(l < r);
                if (c == B) {
                    tot[l] += 1;
                    tot[r] -= 1;
                    insertWeight(u, 1, l, r);
                }
                if ((x == 0 or y == 0 or x == n - 1 or y == m - 1) and c != A) {
                    insertEdge(u, outer, l, r);
                }
            }
        }
    }
    
    for (int i = 0; i < q + 1; i++) {
        tot[i + 1] += tot[i];
    }

    DSU dsu(n * m + 1);
    std::vector<int> ans(q + 1);

    auto dfs = [&](auto& self, int p, int l, int r) -> void {
        int cur = dsu.cur();

        for (auto [u, v] : edgeInfo[p]) {
            dsu.merge(u, v);
        }
        for (auto [x, val] : weightInfo[p]) {
            dsu.addWeight(x, val);
        }
        
        if (r - l == 1) {
            ans[l] = tot[l] - dsu.getWeight(outer);
        } else {
            int mid = l + (r - l) / 2;
            self(self, p * 2, l, mid);
            self(self, p * 2 + 1, mid, r);
        }

        dsu.rollback(cur);
    };
    
    dfs(dfs, 1, 0, q + 1);

    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<std::pair<int, int>>> vec(n * m);
    for (int x = 0; x < n; x++) {
        std::string s;
        std::cin >> s;

        for (int y = 0; y < m; y++) {
            int u = x * m + y;
            vec[u].emplace_back(0, s[y] - '0');
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y, c;
        std::cin >> x >> y >> c;
        x--;
        y--;

        vec[x * m + y].emplace_back(i + 1, c);
    }
    for (auto &v : vec) {
        v.emplace_back(q + 1, 0);
    }

    auto ans1 = solve(1, n, m, q, vec);
    auto ans2 = solve(2, n, m, q, vec);

    for (int i = 0; i < q + 1; i++) {
        if (ans1[i] > ans2[i]) {
            std::cout << "Black\n";
        } else if (ans1[i] < ans2[i]) {
            std::cout << "White\n";
        } else {
            std::cout << "Draw\n";
        }
    }
    
    return 0;
}