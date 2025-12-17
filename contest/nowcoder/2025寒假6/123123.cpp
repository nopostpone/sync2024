#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct State {
    long long a, b, cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, c1, c2;
        cin >> n >> c1 >> c2;
        vector<pair<int, int>> records(n);
        for (int i = 0; i < n; ++i) {
            cin >> records[i].first >> records[i].second;
        }

        vector<vector<State>> dp(n + 1, vector<State>(3));
        // 初始状态（0个记录）
        dp[0][0] = {0, 0, 0};
        dp[0][1] = {0, 0, 0};
        dp[0][2] = {0, 0, 0};

        for (int i = 1; i <= n; ++i) {
            int a = records[i - 1].first;
            int b = records[i - 1].second;

            // 保留不交换
            long long min_cost0 = INF;
            for (int j = 0; j < i; ++j) {
                for (int s = 0; s < 3; ++s) {
                    long long prev_a = dp[j][s].a;
                    long long prev_b = dp[j][s].b;
                    long long prev_cost = dp[j][s].cost;
                    if (a >= prev_a && b >= prev_b && (a > prev_a || b > prev_b)) {
                        if (prev_cost < min_cost0) {
                            min_cost0 = prev_cost;
                        }
                    }
                }
            }
            dp[i][0].a = a;
            dp[i][0].b = b;
            dp[i][0].cost = (min_cost0 == INF) ? INF : min_cost0;

            // 保留交换
            long long min_cost1 = INF;
            int sa = b, sb = a;
            for (int j = 0; j < i; ++j) {
                for (int s = 0; s < 3; ++s) {
                    long long prev_a = dp[j][s].a;
                    long long prev_b = dp[j][s].b;
                    long long prev_cost = dp[j][s].cost;
                    if (sa >= prev_a && sb >= prev_b && (sa > prev_a || sb > prev_b)) {
                        if (prev_cost < min_cost1) {
                            min_cost1 = prev_cost;
                        }
                    }
                }
            }
            dp[i][1].a = sa;
            dp[i][1].b = sb;
            dp[i][1].cost = (min_cost1 == INF) ? INF : (min_cost1 + c2);

            // 删除当前记录
            long long min_del = min({dp[i - 1][0].cost, dp[i - 1][1].cost, dp[i - 1][2].cost});
            dp[i][2].a = dp[i - 1][2].a;
            dp[i][2].b = dp[i - 1][2].b;
            dp[i][2].cost = min_del + c1;

            // 继承前一个状态中a和b的值（取最后一个非删除状态）
            int best_prev = 0;
            long long min_prev_cost = min({dp[i - 1][0].cost, dp[i - 1][1].cost, dp[i - 1][2].cost});
            for (int s = 0; s < 3; ++s) {
                if (dp[i - 1][s].cost == min_prev_cost) {
                    best_prev = s;
                    break;
                }
            }
            dp[i][2].a = dp[i - 1][best_prev].a;
            dp[i][2].b = dp[i - 1][best_prev].b;
        }

        long long ans = min({dp[n][0].cost, dp[n][1].cost, dp[n][2].cost});
        cout << ans << '\n';
    }

    return 0;
}