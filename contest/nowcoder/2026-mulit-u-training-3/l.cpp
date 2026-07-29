#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int dx[] {1, -1, 0, 0};
constexpr int dy[] {0, 0, 1, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector h(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> h[i][j];
        }
    }
    
    std::vector<int> ord(n * m);
    std::iota(ord.begin(), ord.end(), 0);
    rgs::sort(ord, [&](int a, int b) {
        return h[a / m][a % m] > h[b / m][b % m];
    });
    
    std::vector ans(n, std::vector<int>(m, -1));
    auto inside = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m;
    };
    

    for (auto i : ord) {
        int x = i / m;
        int y = i % m;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (not inside(nx, ny)) {
                continue;
            }
            if (ans[nx][ny] == 0) {
                ans[x][y] = 1;
            }
        }
        if (ans[x][y] == -1) {
            ans[x][y] = 0;
        }
    }
    
    {
        int q;
        std::cin >> q;

        while (q--) {
            int r, c;
            std::cin >> r >> c;
            r--;
            c--;

            std::cout << (ans[r][c] ? "First" : "Second") << "\n";
        }
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