#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, k, x0, y0;
    cin >> n >> m >> k >> x0 >> y0;

    x0--, y0--;

    vector a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector vis(n, vector<bool>(m));
    vis[x0][y0] = true;

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> q;
    q.push({a[x0][y0], x0, y0});
    ll now = {};

    constexpr int dx[4] = {0, 0, 1, -1};
    constexpr int dy[4] = {1, -1, 0, 0};

    while (not q.empty()) {
        auto [j, x, y] = q.top();
        q.pop();

        if (now != 0 and 1. * j >= 1. * now / (1. * k)) {
            break;
        }
        now += j;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m) {
                continue;
            }
            if (vis[nx][ny]) {
                continue;
            }
            vis[nx][ny] = true;
            q.push({a[nx][ny], nx, ny});
        }
    }

    cout << now << endl;
    
    return 0;
}