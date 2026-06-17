#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 8;

int Mask[N];

void solve()  {
    int n, m, k;
    std::cin >> n >> m >> k;

    int mask = (1 << m) - 1;
    int need = 0;

    std::vector<int> f(n);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                f[i] |= 1 << j;
                need++;
            }
        }
    }

    std::vector<std::vector<int>> g(k);
    std::vector<int> r(k), c(k);
    std::vector<int> suf(k + 1);
    for (int i = 0; i < k; i++) {
        std::cin >> r[i] >> c[i];

        g[i].resize(r[i]);

        for (int j = 0; j < r[i]; j++) {
            std::string s;
            std::cin >> s;

            for (int l = 0; l < c[i]; l++) {
                if (s[l] == '#') {
                    g[i][j] |= 1 << l;
                    suf[i]++;
                }
            }
        }
    }
    for (int i = k - 1; i > 0; i--) {
        suf[i - 1] += suf[i];
    }

    std::vector<int> cur(n);

    std::vector<std::array<std::array<bool, N>, N>> v1(k);
    for (int t = 0; t < k; t++) {
        for (int ei = 0; ei + r[t] <= n; ei++) {
            for (int ej = 0; ej + c[t] <= m; ej++) {
                // valid ?
                bool valid = true;
                for (int i = 0; i < r[t]; i++) {
                    int f1 = (f[ei + i] >> ej) & Mask[c[t]];
                    int g1 = g[t][i];

                    if ((f1 | g1) != f1) {
                        valid = false;
                    }
                }

                v1[t][ei][ej] = valid;
            }
        }
    }

    int ans = 0;
    [&](this auto &&self, int dep) -> void {
        if (cur == f) {
            ans++;
            return;
        }
        if (dep == k) {
            return;
        }
        if (suf[dep] < need) {
            return;
        }

        // not choose
        self(dep + 1);
        // choose
        for (int ei = 0; ei + r[dep] <= n; ei++) {
            for (int ej = 0; ej + c[dep] <= m; ej++) {
                if (not v1[dep][ei][ej]) {
                    continue;
                }

                // valid ?
                bool valid = true;
                for (int i = 0; i < r[dep]; i++) {
                    int g1 = g[dep][i];
                    int h1 = (cur[ei + i] >> ej) & Mask[c[dep]];
                    h1 = Mask[c[dep]] ^ h1;

                    if ((h1 | g1) != h1) {
                        valid = false;
                    }

                }

                if (not valid) {
                    continue;
                }

                // push
                auto old = cur;
                need -= suf[dep] - suf[dep + 1];
                for (int i = 0; i < r[dep]; i++) {
                    cur[ei + i] |= g[dep][i] << ej;
                }

                self(dep + 1);
                // undo
                need += suf[dep] - suf[dep + 1];
                cur = old;
            }
        }

    } (0);

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0, x = 1; i <= N; i++, x *= 2) {
        Mask[i] = x - 1;
    }

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