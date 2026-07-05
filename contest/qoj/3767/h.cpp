#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;

constexpr int N = 8;

using B = std::bitset<N>;

void solve()  {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<B> grid(n);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        grid[i].set();
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                grid[i].reset(j);
            }
        }
    }

    std::vector<std::array<B, N>> puz(k);
    std::vector<int> r(k), c(k), tran(k);
    for (int i = 0; i < k; i++) {
        std::cin >> r[i] >> c[i];

        for (int x = 0; x < r[i]; x++) {
            std::string s;
            std::cin >> s;

            for (int y = 0; y < c[i]; y++) {
                if (s[y] == '#') {
                    puz[i][x].set(y);
                }
            }
        }
        for (int y = 0; y < c[i]; y++) {
            if (puz[i][0].test(y)) {
                tran[i] = y;
                break;
            }
        }
    }

    std::vector<bool> used(k);

    auto check = [&](int x, int y, int p) {
        if (y < 0 or y >= m) {
            return false;
        }
        if (x + r[p] > n or y + c[p] > m) {
            return false;
        }
        for (int i = 0; i < r[p]; i++) {
            for (int j = 0; j < c[p]; j++) {
                if (puz[p][i].test(j) and grid[i + x].test(j + y)) {
                    return false;
                }
            }
        }
        return true;
    };
    auto fill = [&](int x, int y, int p, int t) {
        for (int i = 0; i < r[p]; i++) {
            for (int j = 0; j < c[p]; j++) {
                if (puz[p][i].test(j)) {
                    grid[i + x].set(j + y, t == 1);
                }
            }
        }
    };

    int ans = 0;

    [&](this auto &&self) -> void {
        int x, y;

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (not grid[i].all()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
            return;
        }
        bool found = false;
        for (x = 0; x < n; x++) {
            if (grid[x].all()) {
                continue;
            }
            for (y = 0; y < m; y++) {
                if (not grid[x].test(y)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (not found) {
            return;
        }

        for (int i = 0; i < k; i++) {
            if (used[i] or not check(x, y - tran[i], i)) {
                continue;
            }
            
            used[i] = true;
            fill(x, y - tran[i], i, 1);
            self();
            fill(x, y - tran[i], i, -1);
            used[i] = false;
        }
    } ();

    std::cout << ans << "\n";
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
3
3 4 5
..#.
..#.
....
3 2
.#
.#
##
3 2
##
##
#.
3 2
.#
.#
##
1 3
###
2 1
#
#
2 2 2
..
..
1 1
#
1 2
##
2 2 3
..
..
1 1
#
1 1
#
1 2
##



1
2 2 3
..
..
1 1
#
1 1
#
1 2
##

*/