#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

constexpr int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    auto in = [&](int x, int y) {
        return x >= 0 and y >= 0 and x < n and y < m;
    };

    vector vis(n, vector<int>(m));
    {
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vis[0][0] = 1;

        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (in(nx, ny) and s[nx][ny] == '.' and not vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    if (vis[n - 1][m - 1]) {
        cout << 0 << "\n";
        return;
    }

    {
        queue<pair<int, int>> q;
        q.emplace(n - 1, m - 1);
        vis[n - 1][m - 1] = 2;

        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (in(nx, ny) and s[nx][ny] == '.' and not vis[nx][ny]) {
                    vis[nx][ny] = 2;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}