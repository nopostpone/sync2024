#include <bits/stdc++.h>

using i64 = long long;

std::string fmt = "RSP";

bool win(int a, int b) {
    return (b - a == 1) or (a - b == 2);
}

std::vector<std::array<int, 3>> p1;
std::vector<std::pair<int, int>> p2;

int findArr(auto a) {
    std::sort(a.begin(), a.end());
    return std::find(p1.begin(), p1.end(), a) - p1.begin();
}
int findId(int x, int y) {
    return std::find(p2.begin(), p2.end(), std::pair{x, y}) - p2.begin();
}

std::array<double, 100> f[200];

void solve() {
    int k;
    std::cin >> k;

    std::string sa, sb;
    std::cin >> sa >> sb;

    std::array<int, 3> a, b;
    for (int i = 0; i < 3; i++) {
        a[i] = fmt.find(sa[i]);
        b[i] = fmt.find(sb[i]);
    }
    int p = findId(findArr(a), findArr(b));

    int m = std::min(k, 100);
    double ans = f[m][p];
    if (k > m) {
        ans += (f[m][p] - f[m - 1][p]) * (k - m);
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            for (int k = j; k < 3; k++) {
                p1.push_back({i, j, k});
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            p2.push_back({i, j});
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            auto [ax, bx] = p2[j];
            auto na = p1[ax];
            auto nb = p1[bx];

            auto get = [&](int p, int q) {
                auto ta = na, tb = nb;
                double res = 0;
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        ta[p] = ii;
                        tb[q] = jj;

                        auto nx = findArr(ta);
                        auto ny = findArr(tb);

                        int nj = nx * 10 + ny;
                        res += 1. / 9 * f[i][nj];
                    }
                }
                return res;
            };

            for (int p = 0; p < 3; p++) {
                double res = INFINITY;
                for (int q = 0; q < 3; q++) {
                    double r = get(p, q);
                    if (win(na[p], nb[q])) {
                        r += 3;
                    } else if (not win(nb[q], na[p])) {
                        r += 1;
                    }
                    res = std::min(res, r);
                }
                f[i + 1][j] = std::max(f[i + 1][j], res);
            }
        }
    }

    int t;
    std::cin >> t;

    std::cout << std::fixed << std::setprecision(6);

    while (t--) {
        solve();
    }
}