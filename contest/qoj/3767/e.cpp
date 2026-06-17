#include <bits/stdc++.h>

using i64 = long long;

namespace rgs = std::ranges;

constexpr int dx[] {0, 0, 1, -1};
constexpr int dy[] {1, -1, 0, 0};

void solve() {
    int n, m;
    std::cin >> n >> m;

    bool fl = false;
    if (m < n) {
        std::swap(n, m);
        fl = true;
    }

    std::vector a(n, std::vector<int>(m));
    if (m >= 5) {
        for (int i = 2; i < m; i += 2) {
            a[0][i] = a[0][i - 2] + 1;
        }
        a[0][1] = (m + 1) / 2;
        for (int i = 3; i < m; i += 2) {
            a[0][i] = a[0][i - 2] + 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = a[i - 1][j] + m;
            }
        }
    } else if (n == 2 and m == 3) {
        a = {{0, 4, 2}, {3, 1, 5}};
    } else if (n == 3 and m == 3) {
        a = {{0, 6, 8}, {3, 1, 4}, {5, 7, 2}};
    } else if (n == 3 and m == 4) {
        a = {{0, 4, 2}, {3, 1, 5}, {6, 10, 8}, {9, 7, 11}};
        std::swap(n, m);
        fl ^= 1;
    } else if (n == 4 and m == 4) {
        a = {{0, 5, 2, 7}, {4, 1, 6, 3}, {8, 13, 10, 15}, {12, 9, 14, 11}};
    } else if (n == 2 and m == 4) {
        a = {{0, 5, 2, 7}, {4, 1, 6, 3}};
    } else if (n == 1 and m == 1) {
    } else {
        std::cout << "No\n";
        return;
    }
    std::cout << "Yes\n";

    // std::cerr << n << " " << m << "\n";


    // std::cerr << 1 << "\n";

    if (fl) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[j][i] << " \n"[j == n - 1];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << a[i][j] << " \n"[j == m - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 or nj < 0 or ni >= n or nj >= m) {
                    continue;
                }
                // std::cerr << i << " " << j << " " << ni << " " << nj << "\n";
                int x = a[i][j];
                int y = a[ni][nj];

                assert(((x + 1) % (n * m)) != y);
                assert(((y + 1) % (n * m)) != x);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}

/*
2
3 4
1 3

11
1 1
1 2
1 3
1 4
1 5
2 100
3 23
2 3
2 4
4 4
3 4
*/