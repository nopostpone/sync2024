#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    array<vector<pair<int, int>>, 26> vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = s[i][j] - 'a';
            if (0 <= x and x < 26) {
                vec[x].emplace_back(i, j);
            }
        }
    }

    vector f(n, vector<int>(m, (int)1e9));
    f[0][0] = 0;

    deque<pair<int, int>> q;
    q.emplace_back();

    auto inside = [&](int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < m;
    };

    constexpr int dx[] {1, -1, 0, 0};
    constexpr int dy[] {0, 0, 1, -1};

    array<bool, 26> used {};

    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        
        int c = s[x][y] - 'a';

        if (0 <= c and c < 26 and not used[c]) {
            used[c] = true;
            for (auto [nx, ny] : vec[c]) {
                if (f[nx][ny] > f[x][y] + 1) {
                    f[nx][ny] = f[x][y] + 1;
                    q.emplace_front(nx, ny);
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (not inside(nx, ny)) {
                continue;
            }
            if (s[nx][ny] == '#' or f[nx][ny] <= f[x][y] + 1) {
                continue;
            }
            f[nx][ny] = f[x][y] + 1;
            q.emplace_back(nx, ny);
        }
    }

    int ans = f[n - 1][m - 1];

    if (ans == (int)1e9) {
        ans = -1;
    }
    cout << ans << "\n";

    return 0;
}