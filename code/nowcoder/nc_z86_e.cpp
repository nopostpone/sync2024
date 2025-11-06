// https://ac.nowcoder.com/acm/contest/104637/e
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const int S = accumulate(a.begin(), a.end(), 0);

    ranges::sort(a);

    vector dp(S + 1, array<bool, 4>{});
    dp[0][0] = true;
    int ans = inf;
    for (int i = 0; i < n; i++) {
        for (int s = S; s >= 0; s--) {
            for (int c = 0; c <= 3; c++) {
                if (not dp[s][c]) {
                    continue;
                }
                dp[s + a[i]][min(3, c + 1)] = true;
                if (c >= 2 and a[i] < s) {
                    ans = min(ans, s + a[i]);
                }
            }
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}