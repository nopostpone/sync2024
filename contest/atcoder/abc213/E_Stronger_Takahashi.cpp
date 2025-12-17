#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

constexpr int dx[] = {1, 0, 0, -1};
constexpr int dy[] = {0, -1, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    deque<array<int, 2>> q;
    q.push_back({});

    vector f(n, vector<int>(m, inf));
    vector vis(n, vector<bool>(m));
    f[0][0] = 0;

    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();

        if (vis[x][y]) {
            continue;
        }
        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m
                or s[nx][ny] == '#' or f[nx][ny] < f[x][y]) {
                continue;
            }
            f[nx][ny] = f[x][y];
            q.push_front({nx, ny});
        }
        for (int nx = x - 2; nx <= x + 2; nx++) {
            for (int ny = y - 2; ny <= y + 2; ny++) {
                if (abs(x - nx) + abs(y - ny) == 4) {
                    continue;
                }
                if (nx < 0 or ny < 0 or nx >= n or ny >= m
                    or f[nx][ny] < f[x][y] + 1) {
                    continue;
                }
                f[nx][ny] = f[x][y] + 1;
                q.push_back({nx, ny});
            }
        }
    }
    cout << f[n - 1][m - 1] << "\n";

    return 0;
}