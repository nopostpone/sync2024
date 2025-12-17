#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto inside = [&](int x, int y) {
        return x >= 0 and y >= 0 and x < n and y < m;
    };
    vector f(n, vector<int>(m, inf));
    
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                f[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inside(nx, ny) and f[nx][ny] == inf) {
                q.emplace(nx, ny);
                if (a[nx][ny]) {
                    f[nx][ny] = 0;
                } else {
                    f[nx][ny] = f[x][y] + 1;
                }
            }
        }
    }

    auto check = [&](int t) {
        int line[] = {-inf, inf, -inf, inf};
        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (f[x][y] > t) {
                    line[0] = max(line[0], x + y - t);
                    line[1] = min(line[1], x + y + t);
                    line[2] = max(line[2], y - x - t);
                    line[3] = min(line[3], y - x + t);
                }
            }
        }
        if (line[0] > line[1] or line[2] > line[3]) {
            return false;
        }
        if (line[0] < line[1] or line[2] < line[3]) {
            return true;
        }
        return (line[0] + line[2]) % 2 == 0;
    };
    int lo = 0, hi = n + m;
    while (lo < hi) {
        int x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }

    cout << lo << "\n";
    
    return 0;
}