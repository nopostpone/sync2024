#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;

    vector<pair<int, char>> opt(q);
    for (int i = 0; i < q; i++) {
        cin >> opt[i].first >> opt[i].second;
        opt[i].first--;
    }

    vector dis(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int ri{}, lj{1};
            for (auto [id, mov] : opt) {
                if (id == i) {
                    ri += (mov == '+');
                }
                if (id == j) {
                    lj += (mov == '-');
                }
                if (ri == lj) {
                    ri--;
                    dis[i][j]++;
                }
            }
        }
    }

    vector dp(n, vector<int>(1 << n, inf));
    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 1;
    }
    for (int s = 0; s < (1 << n); s++) {
        for (int d = 0; d < n; d++) {
            if (dp[d][s] == inf) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if ((s >> i) & 1) {
                    continue;
                }
                dp[i][s | (1 << i)] = min(dp[i][s | (1 << i)], dp[d][s] + dis[d][i]);
            }
        }
    }

    int ans{inf};
    for (int i = 0; i < n; i++) {
        int x = dp[i].back();
        for (auto [id, mov] : opt) {
            if (id == i and mov == '+') {
                x++;
            }
        }
        ans = min(ans, x);
    }

    cout << ans << endl;
    
    return 0;
}