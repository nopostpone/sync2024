#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector a(n, vector<int>(2 * n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = n - 1 - i; j < n + i; j++) {
            cin >> a[i][j];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 2 * n + 1; j++) {
    //         cerr << a[i][j] << " \n"[j == 2 * n];
    //     }
    // }

    vector f(n, vector<int>(2 * n + 1, -1));
    f[0][n - 1] = 0;
    queue<array<int, 5>> q;

    q.push({0, n - 1, 1, 2, 3});
    while (not q.empty()) {
        auto [x, y, l, m, r] = q.front();
        q.pop();

        if (y - 1 >= 0 and a[x][y - 1] == l and f[x][y - 1] == -1) {
            f[x][y - 1] = f[x][y] + 1;
            q.push({x, y - 1, m, r, a[x][y]});
        }
        if (y + 1 < n + x + 1 and a[x][y + 1] == r and f[x][y + 1] == -1) {
            f[x][y + 1] = f[x][y] + 1;
            q.push({x, y + 1, a[x][y], l, m});
        }
        
        if ((y - n + x) % 2 != 0) {
            if (x + 1 < n and a[x + 1][y] == m and f[x + 1][y] == -1) {
                f[x + 1][y] = f[x][y] + 1;
                q.push({x + 1, y, l, a[x][y], r});
            }
        } else {
            if (x - 1 >= 0 and a[x - 1][y] == m and f[x - 1][y] == -1) {
                f[x - 1][y] = f[x][y] + 1;
                q.push({x - 1, y, l, a[x][y], r});
            }
        }
    }

    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << f[x][n - x + y - 1] << "\n";

    return 0;
}

/*
3
4
3 2 3
4 3 2 1 3
3 1
*/