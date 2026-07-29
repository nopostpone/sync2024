#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int V = 1e5;

constexpr int dx[] {0, 0, -1, 1};
constexpr int dy[] {1, -1, 0, 0};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<std::pair<int, int>>> vec(V);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            std::cin >> a;
            a--;

            vec[a].emplace_back(i, j);
        }
    }

    std::vector ans(n, std::vector<int>(m, -1));
    for (int v = V - 1; v >= 0; v--) {
        for (auto [x, y] : vec[v]) {
            ans[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx and nx < n and 0 <= ny and ny < m and ans[nx][ny] == 0) {
                    ans[x][y] = 1;
                }
            }
        }
    }
 
    for (int _ = 0; _ < q; _++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        std::cout << ans[x][y] << "\n";
    }
}