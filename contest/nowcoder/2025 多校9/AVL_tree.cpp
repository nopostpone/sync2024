#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

array<int, 28> f;

void solve() {
    int n;
    cin >> n;

    int m = min(n, 27);
    
    vector<pair<int, int>> son(n + 1);
    vector<int> siz(n + 1, 1);
    siz[0] = 0;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        son[i] = {l, r};
    }

    vector dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; i++) {
        dp[0][i] = f[i];
    }
    auto dfs = [&](auto &&self, int x) -> void {
        if (x == 0) {
            return;
        }

        auto [l, r] = son[x];
        self(self, l);
        self(self, r);
        siz[x] += siz[l] + siz[r];

        dp[x][0] = siz[x];
        dp[x][1] = dp[l][0] + dp[r][0];
        for (int h = 2; h <= m; h++) {
            dp[x][h] = min({dp[l][h - 1] + dp[r][h - 2], dp[l][h - 2] + dp[r][h - 1], dp[l][h - 1] + dp[r][h - 1]});
        }
    };
    dfs(dfs, 1);

    cout << ranges::min(dp[1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 27; i++) {
        f[i] = f[i - 1] + f[i - 2] + 1;
    }

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}