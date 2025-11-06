#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 差分优化dp
// n 很大，m 很小，用差分数组维护区间的修改
// 复杂度从 O(nm) 变为 O(n + m^2)

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> dp(m + 1), d(m + 2);

    int cnt{};
    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;
        if (now == 0) {
            cnt++;
            dp[0] += d[0];
            for (int j = 1; j <= cnt; j++) {
                d[j] += d[j - 1];
                dp[j] += d[j];
            }
            for (int j = cnt; j; j--) {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            fill(d.begin(), d.end(), 0);
        }
        if (now > 0 and now <= cnt) {
            d[now]++;
            d[cnt + 1]--;
        }
        if (now < 0 and -now <= cnt) {
            d[0]++;
            d[cnt + now + 1]--;
        }
    }
    dp[0] += d[0];
    for (int j = 1; j <= m; j++) {
        d[j] += d[j - 1];
        dp[j] += d[j];
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}