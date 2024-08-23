// https://ac.nowcoder.com/acm/contest/88455/C
// 很搞的搜索题
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> mp(n);
    for (int i = 0; i < n; i++)
        cin >> mp[i];

    using pii = array<int, 2>;

    pii ST, ED;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'S') {
                ST = {i, j};
            }
            if (mp[i][j] == 'E') {
                ED = {i, j};
            }
        }
    }

    constexpr int dx[] = {1, -1, 0, 0};
    constexpr int dy[] = {0, 0, 1, -1};

    vector stvis(n, vector<bool>(m)), edvis(n, vector<bool>(m));
    stvis[ST[0]][ST[1]] = edvis[ED[0]][ED[1]] = true;

    set<int> X, Y;

    auto check = [&](int x, int y, bool isST) {
        return x >= 0 and y >= 0 and x < n and y < m and mp[x][y] != '#' and (isST ? !stvis[x][y] : !edvis[x][y]);
    };

    queue<pii> q;

    q.push(ST);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        X.insert(x), X.insert(x + 1), X.insert(x - 1);
        Y.insert(y), Y.insert(y + 1), Y.insert(y - 1);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny, 1)) {
                stvis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    bool ok = false;

    q.push(ED);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (X.find(x) != X.end() or Y.find(y) != Y.end()) {
            ok = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny, 0)) {
                edvis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    cout << (ok ? "YES" : "NO");

    return 0;
}