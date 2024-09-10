#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

struct Node {
    int v, x, y;
    constexpr bool operator<(const Node &o) const {
        return v > o.v;
    }
};

constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int h, w, y;
    cin >> h >> w >> y;

    vector a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    vector vis(h, vector<bool>(w));

    priority_queue<Node> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 or j == 0 or i == h - 1 or j == w - 1) {
                q.push({a[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    auto check = [&](int x, int y) {
        if (x < 0 or x >= h or y < 0 or y >= w) {
            return false;
        }
        return not vis[x][y];
    };

    int ans = h * w;
    for (int now = 1; now <= y; now++) {
        while (!q.empty()) {
            auto [v, x, y] = q.top();
            if (v > now) {
                break;
            }

            q.pop();
            ans--;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(nx, ny)) {
                    q.push({a[nx][ny], nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}