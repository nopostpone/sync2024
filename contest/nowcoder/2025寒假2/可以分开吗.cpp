#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    array<int, 4> dx = {0, 0, 1, -1};
    array<int, 4> dy = {1, -1, 0, 0};

    vector vis(n, vector<bool>(m));
    auto check = [&](int x, int y, int c) {
        if (x < 0 or y < 0 or x >= n or y >= m) {
            return false;
        }
        return (not vis[x][y]) and s[x][y] == char('0' + c);
    };

    set<pair<int, int>> st;
    auto upd = [&](int x, int y) {
        for (int i = 0; i < 4; i++) {
            if (check(x + dx[i], y + dy[i], 0)) {
                st.insert({x + dx[i], y + dy[i]});
            }
        }
    };

    auto bfs = [&](int x0, int y0) -> int {
        queue<pair<int, int>> q;
        q.push({x0, y0});

        st.clear();

        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            upd(x, y);
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (not check(nx, ny, 1)) {
                    continue;
                }
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        return st.size();
    };

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) {
                continue;
            }
            if (s[i][j] == '1') {
                vis[i][j] = true;
                ans = min(ans, bfs(i, j));
            }
        }
    }
    cout << ans << "\n";

    return 0;
}