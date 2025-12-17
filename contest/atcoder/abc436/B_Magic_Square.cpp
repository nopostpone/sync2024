#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector a(n, vector<int>(n));
    queue<pair<int, int>> q;

    q.emplace(0, (n - 1) / 2);
    a[0][(n - 1) / 2] = 1;
    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        {
            int nx = (x + n - 1) % n;
            int ny = (y + 1) % n;
            if (a[nx][ny] == 0) {
                q.emplace(nx, ny);
                a[nx][ny] = a[x][y] + 1;
                continue;
            }
        }
        {
            int nx = (x + 1) % n;
            int ny = y;
            if (a[nx][ny] == 0) {
                q.emplace(nx, ny);
                a[nx][ny] = a[x][y] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }


    return 0;
}