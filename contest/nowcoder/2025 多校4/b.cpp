#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int dx[] = {0, 0, -1, 1};
constexpr int dy[] = {1, -1, 0, 0};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector far(n, vector<int>(m));
    
    auto valid = [&](int x, int y) {
        return x >= 0 and y >= 0 and x < n and y < m and s[x][y] == '0';
    };

    auto bfs = [&](int sx, int sy) {
        far[sx][sy] = sy;
        queue<pair<int, int>> q;
        q.emplace(sx, sy);

        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 1; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (not valid(nx, ny)) {
                    continue;
                }

                if (far[nx][ny] < far[x][y]) {
                    far[nx][ny] = far[x][y];
                    q.emplace(nx, ny);
                }
            }
        }
    };
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '0' and far[i][j] == 0) {
                bfs(i, j);
            }
        }
    }
    vector vis(n, vector<bool>(m));
    queue<pair<int, int>> q;
    vis[0][0] = true;

    q.emplace(0, 0);
    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (far[x][y] != m - 1) {
            cout << "Yes\n";
            return;
        }

        for (int i = 2; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (not valid(nx, ny) or vis[nx][ny]) {
                continue;
            }
            vis[nx][ny] = true;
            q.emplace(nx, ny);
        }
        if (int ny = y + 1; valid(x, ny) and not vis[x][ny]) {
            vis[x][ny] = true;
            if (far[x][ny] >= min(m - 1, y + k)) {
                q.emplace(x, ny);
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}