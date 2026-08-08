#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int dx[] {1, -1, 0, 0};
constexpr int dy[] {0, 0, 1, -1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    int A = n * m;

    std::vector<int> a(A), w(A), max(A), siz(A);
    std::vector<int> parent(A);
    std::iota(parent.begin(), parent.end(), 0);

    auto find = [&](auto &&self, int x) -> int {
        if (x != parent[x]) {
            int y = self(self, parent[x]);
            max[x] = std::max(max[x], max[parent[x]]);
            parent[x] = y;
        }
        return parent[x];
    };

    int ans = 0;
    auto decode = [&](int &x, int &y) {
        x ^= ans;
        y ^= ans;
    };

    for (int _ = 0; _ < q; _++) {
        int typ, x, y;
        std::cin >> typ >> x >> y;
        decode(x, y);
        x--;
        y--;

        int u = x * m + y;
        if (typ == 1) {
            siz[u] = 1;

            std::cin >> a[u];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 or ny < 0 or nx >= n or ny >= m) {
                    continue;
                }
                int v = nx * m + ny;
                if (siz[v] == 0) {
                    continue;
                }
                v = find(find, v);
                if (u == v) {
                    continue;
                }
                siz[u] += siz[v];

                w[v] = a[u];
                max[v] = std::max(0, a[u] - siz[v] + 1);
                parent[v] = u;
            }

            ans = siz[u] - 1;
        } else {
            find(find, u);
            ans = std::max(0, max[u] - a[u]);
        }
        std::cout << ans << "\n";
    }
}