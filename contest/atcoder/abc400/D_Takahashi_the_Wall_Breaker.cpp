#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;
constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;

    vector dp(n, vector<int>(m, inf));

    auto inside = [&](int x, int y) {
        return x >= 0 and y >= 0 and x < n and y < m;
    };
    auto valid = [&](int x, int y) {
        if (inside(x, y)) {
            return s[x][y] == '.';
        }
        return false;
    };

    queue<array<int, 3>> edges;
    auto work = [&](int ox, int oy, int ot) {
        dp[ox][oy] = ot;
        queue<array<int, 2>> q;
        q.push({ox, oy});

        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            bool ok = false;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (inside(nx, ny) and s[nx][ny] == '#') {
                    ok = true;
                }
                if (valid(nx, ny) and dp[nx][ny] == inf) {
                    dp[nx][ny] = ot;
                    q.push({nx, ny});
                }
            }
            if (ok) {
                edges.push({x, y, ot + 1});
            }
        }
    };
    work(C, D, 0);

    while (dp[A][B] == inf) {
        assert(not edges.empty());
        auto [x, y, t] = edges.front();
        edges.pop();
        for (int j = 1; j <= 2; j++) {
            for (int i = 0; i < 4; i++) {
                int nx = x + j * dx[i];
                int ny = y + j * dy[i];
                if (not inside(nx, ny)) {
                    continue;
                }
                if (dp[nx][ny] == inf) {
                    work(nx, ny, t);
                }
            }
        }
    }
    cout << dp[A][B] << "\n";
    
    return 0;
}