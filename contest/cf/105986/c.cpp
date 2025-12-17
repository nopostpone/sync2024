#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int dx[] = {0, 0, -1, 1};
constexpr int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector a(n, vector<int>(m));
    while (k--) {
        int x, y, dis;
        cin >> x >> y >> dis;
        x--;
        y--;

        int x1 = max(0, x - dis);
        int y1 = max(0, y - dis);
        int x2 = min(n - 1, x + dis);
        int y2 = min(m - 1, y + dis);

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                a[i][j]++;
            }
        }
    }

    vector dis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0) {
                q.emplace(i, j);
                dis[i][j] = 0;
            }
        }
    }

    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 and ny >= 0 and nx < n and ny < m and dis[nx][ny] == -1) {
                dis[nx][ny] = dis[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    int ans = -1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            ans = max(ans, dis[x][y] - 1);
        }
    }

    cout << ans << "\n";

    return 0;
}

/*
5 6 2
2 2 2
5 6 1

1

5 5 1
3 3 2

-1
*/
