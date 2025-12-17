#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

constexpr int inf = 1e9;

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto valid = [&](int x, int y) {
        if (x < 0 or y < 0 or x >= n or y >= m) {
            return false;
        }
        return a[x][y] == '1';
    };

    auto bfs = [&](const vector<pair<int, int>> &st, int t) {
        queue<pair<int, int>> q;

        vector f(n, vector<int>(m, inf));
        for (auto [x, y] : st) {
            q.emplace(x, y);
            f[x][y] = t;
        }

        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (not valid(x1, y1)) {
                    continue;
                }

                for (int j = 0; j < 8; j++) {
                    int x2 = x1 + dx[j];
                    int y2 = y1 + dy[j];
                    if (not valid(x2, y2)) {
                        continue;
                    }
                    if (f[x2][y2] == inf) {
                        f[x2][y2] = f[x][y] + 2;
                        q.emplace(x2, y2);
                    }
                }
            }
        }

        return f[n - 1][m - 1];
    };

    int d[2] {};
    d[0] = bfs({{}}, 0);

    vector<pair<int, int>> nxt;
    for (int i = 0; i < 8; i++) {
        int x = dx[i];
        int y = dy[i];

        if (valid(x, y)) {
            nxt.emplace_back(x, y);
        }
    }

    d[1] = bfs(nxt, 1);

    if (d[0] == inf and d[1] == inf) {
        cout << -1 << "\n";
        return;
    }

    int t[2];
    for (int i = 0; i < 2; i++) {
        t[i] = (d[i] + r - 1) / r;
    }
    
    int ans = inf;
    if (l == r) {
        if (l % 2) {
            for (int i = 0; i < 2; i++) {
                if (d[i] != inf) {
                    ans = min(ans, t[i] + (t[i] % 2 != d[i] % 2));
                }
            }
        } else if (d[0] != inf) {
            ans = t[0];
        }
    } else {
        ans = min(t[0], t[1]);
    }

    if (ans == inf) {
        ans = -1;
    }

    cout << ans << "\n";
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