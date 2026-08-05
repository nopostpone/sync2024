#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector r(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> r[i][j];
        }
    }

    std::vector deg(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            deg[i][j] = 4;
            deg[i][j] -= i == 0;
            deg[i][j] -= j == 0;
            deg[i][j] -= i == n - 1;
            deg[i][j] -= j == m - 1;
        }
    }
    
    std::vector f(n, std::vector<int>(m));

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (r[i][j] > 0) {
                q.emplace(i, j);
            }
        }
    }

    static constexpr int dx[] {0, 0, 1, -1};
    static constexpr int dy[] {1, -1, 0, 0};

    i64 ans = 0;
    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        int need = (r[x][y] - f[x][y] + deg[x][y]) / (deg[x][y] + 1);
        f[x][y] += need * (deg[x][y] + 1);
        ans += need;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                bool fl = f[nx][ny] >= r[nx][ny];
                f[nx][ny] -= need;
                if (fl and f[nx][ny] < r[nx][ny]) {
                    q.emplace(nx, ny);
                }
            }
        }
    }
    std::cout << ans << "\n";
}