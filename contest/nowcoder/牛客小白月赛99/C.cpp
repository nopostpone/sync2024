#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    pair<int, int> st, ed;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'S') {
                st = {i, j};
            } else if (mp[i][j] == 'E') {
                ed = {i, j};
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    vector vis(n, vector<bool>(m));

    auto check = [&](int x, int y) {
        return x >= 0 and y >= 0 and x < n and y < m and !vis[x][y];
    };

    auto modify = [&](int x, int y, char c, char d) {
        if (mp[x][y] == c) {
            mp[x][y] = d;
        }
        if (c == '#') {
            vis[x][y] = 0;
        }
    };

    auto upd = [&](int i, int x, int y, char c, char d) {
        if (i == 0) {
            for (int j = x + 1; j < n; j++) {
                modify(j, y, c, d);
            }
        } else if (i == 1) {
            for (int j = x - 1; ~j; j--) {
                modify(j, y, c, d);
            }
        } else if (i == 2) {
            for (int j = y + 1; j < m; j++) {
                modify(x, j, c, d);
            }
        } else if (i == 3) {
            for (int j = y - 1; ~j; j--) {
                modify(x, j, c, d);
            }
        }
    };

    bool used = 0;

    function<void(int, int)> dfs = [&](int x, int y) {
        if (pair{x, y} == ed) {
            cout << "YES" << endl;
            exit(0);
        }
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny)) {
                if (mp[nx][ny] == '#' and used == 0) {
                    upd(i, x, y, '#', 'o');
                    used = 1;
                    dfs(nx, ny);
                    upd(i, x, y, 'o', '#');
                    used = 0;
                }
                if (mp[nx][ny] != '#') {
                    dfs(nx, ny);
                }
            }
        }
    };

    dfs(st.first, st.second);

    cout << "NO" << endl;

    return 0;
}