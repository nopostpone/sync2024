//
// Created by 钟梓皓 on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = long long;
using pii = std::pair<int, int>;
using piii = std::tuple<int, int, int>;
using piiii = std::tuple<int, int, int, int>;
using pll = std::pair<ll, ll>;
using plll = std::tuple<ll, ll, ll>;
using pllll = std::tuple<ll, ll, ll, ll>;

class Solver {
public:
    Solver() {}

    static void update(std::uint8_t &u, std::uint8_t v) { u = std::min(u, v); }

    void solve() {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::vector<std::vector<std::uint8_t>> dp(n);
        constexpr std::uint8_t INF = 0xff;
        for (int i = 0; i < n; ++i) {
            dp[i].resize(n, INF);
            dp[i][i] = 0;
        }
        for (int i = n - 2; i >= 0; --i) {
            std::vector<int> a_copy = a;
            std::vector<int> map(n + 1, -1);
            std::vector<int> cnt(n + 1);
            int counter = 0;
            for (int j = i; j < n; ++j) {
                ++cnt[a_copy[j]];
                if (cnt[a_copy[j]] == 2) {
                    map[a_copy[j]] = counter++;
                }
            }
            for (int j = i; j < n; ++j) {
                a_copy[j] = map[a_copy[j]];
            }
            std::vector<int> state1(n), state2(n + 1), state(n + 1);
            for (int j = i; j < n; ++j) {
                state1[j] = 1 << a_copy[j];
                if (j > i) {
                    state1[j] |= state1[j - 1];
                }
            }
            for (int j = n - 1; j >= i; --j) {
                state2[j] = 1 << a_copy[j];
                state2[j] |= state2[j + 1];
            }
            for (int j = i + 1; j <= n; ++j) {
                state[j] = state1[j - 1] & state2[j];
            }
            std::vector<std::vector<std::uint8_t>> dp1(n + 1);
            for (int j = i; j <= n; ++j) {
                dp1[j].resize(1 << counter, INF);
            }
            dp1[i][0] = 0;
            for (int j = i; j < n; ++j) {
                int num = a_copy[j];
                for (unsigned j_state = (((1 << counter) - 1) & state[j]);;
                     j_state = ((j_state - 1) & state[j])) {
                    if (dp1[j][j_state] != INF) {
                        if (num != -1 && (j_state & (1 << num)) != 0) {
                        } else {
                            auto n_state = j_state;
                            if (num != -1) {
                                n_state |= 1 << num;
                            }
                            n_state &= state[j + 1];
                            update(dp1[j + 1][n_state], dp1[j][j_state]);
                        }
                        for (int k = j + 1; k <= n; ++k) {
                            if (dp[j][k - 1] != INF) {
                                update(dp1[k][j_state & state[k]],
                                       dp1[j][j_state] + dp[j][k - 1] + 1);
                            }
                        }
                    }
                    if (j_state == 0) {
                        break;
                    }
                }
            }
            for (int j = i + 1; j <= n; ++j) {
                for (unsigned j_state = (((1 << counter) - 1) & state[j]);;
                     j_state = ((j_state - 1) & state[j])) {
                    update(dp[i][j - 1], dp1[j][j_state]);
                    if (j_state == 0) {
                        break;
                    }
                }
            }
        }
        std::cout << static_cast<int32_t>(dp[0][n - 1]) << '\n';
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int test = 1;
    std::cin >> test;
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18);
    while (test--) {
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif // WORKSPACE_TEMPLATE_H