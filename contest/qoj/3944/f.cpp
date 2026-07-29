#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int inf = 1e9;

void solve() {
    int n;
    std::string str;
    std::cin >> n >> str;

    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        if (str[i] == '9') {
            str[i] = '0';
        }
        pre[i + 1] = pre[i] + str[i] - '0';
        if (pre[i + 1] >= 9) {
            pre[i + 1] -= 9;
        }
    }
    
    std::vector<std::array<int, 9>> nxt(n + 1);
    nxt[n].fill(-1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 9; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][str[i] - '0'] = i + 1;
    }

    std::array<std::array<int, 9>, (1 << 9)> dp;
    for (auto &arr : dp) {
        arr.fill(inf);
    }
    dp[1][0] = 0;

    for (int s = 0; s < 1 << 9; s++) {
        for (int i = 0; i < 9; i++) {
            if (dp[s][i] == inf) {
                continue;
            }
            for (int d = 1; d < 9; d++) {
                int j = i + d;
                if (j >= 9) {
                    j -= 9;
                }

                if (s >> j & 1) {
                    continue;
                }
                int k = nxt[dp[s][i]][d];
                if (k != -1) {
                    dp[s | (1 << j)][j] = std::min(dp[s | (1 << j)][j], k);
                }
            }
        }
    }

    int best = 0;
    for (int s = 0; s < 1 << 9; s++) {
        if (std::count(dp[s].begin(), dp[s].end(), inf) == dp[s].size()) {
            continue;
        }
        if (__builtin_popcount(s) > __builtin_popcount(best)) {
            best = s;
        }
    }

    std::vector<int> ans;
    if (best != 1) {
        int i = std::find_if(dp[best].begin(), dp[best].end(), [&](int x) {
            return x != inf;
        }) - dp[best].begin();

        int s = best;
        while (s != 1) {
            ans.push_back(dp[s][i]);

            int ps = s ^ (1 << i);
            for (int j = 0; j < 9; j++) {
                if (dp[ps][j] == inf) {
                    continue;
                }

                int d = (i >= j) ? i - j : i - j + 9;
                if (nxt[dp[ps][j]][d] == dp[s][i]) {
                    i = j;
                    s = ps;
                    break;
                }
            }
        }
        std::reverse(ans.begin(), ans.end());
    }

    if (ans.empty()) {
        std::cout << 0 << "\n";
    } else {
        std::cout << ans.size() << " ";
        for (auto i : ans) {
            std::cout << i << " \n"[i == ans.back()];
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