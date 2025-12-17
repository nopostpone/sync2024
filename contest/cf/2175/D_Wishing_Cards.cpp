#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e12;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector dp(k + 1, vector<i64>(k + 1, -inf));
    dp[0][0] = 0;

    int cnt = 0;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        if (mx >= a[i]) {
            cnt++;
            continue;
        }
        mx = a[i];
        for (int m = 0; m <= k; m++) {
            for (int s = 0; s <= k; s++) {
                dp[m][s] += 1ll * m * cnt;
            }
        }
        cnt = 0;

        vector ndp(k + 1, vector<i64>(k + 1, -inf));
        for (int m = 0; m <= k; m++) {

            int x = min(m, a[i]);

            deque<int> dq;
            for (int t = 0; t <= k; t++) {
                while (not dq.empty() and dp[m][dq.back()] <= dp[m][t]) {
                    dq.pop_back();
                }
                dq.push_back(t);
                if (not dq.empty() and dq.front() < t - x) {
                    dq.pop_front();
                }
                if (not dq.empty()) {
                    ndp[m][t] = max(ndp[m][t], dp[m][dq.front()] + m);
                }
            }
        }
        
        for (int s = 0; s <= k; s++) {
            i64 pre = -inf;

            for (int m = 0; m <= min(k, a[i]) - 1; m++) {
                pre = max(pre, dp[m][s]);
                int b = m + 1;
                
                if (s + b <= k) {
                    ndp[b][s + b] = max(ndp[b][s + b], pre + b);
                }
            }
        }
        dp = move(ndp);

    }
    for (int m = 0; m <= k; m++) {
        for (int s = 0; s <= k; s++) {
            dp[m][s] += 1ll * m * cnt;   
        }
    }

    i64 ans = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}