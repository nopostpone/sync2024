#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

constexpr void chmin(auto &x, auto y) {
    if (y < x) {
        x = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    array<int, 4> a;
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> o;
    for (int i = 0; i < 4; i++) {
        o.emplace_back(1 << i, a[0]);
    }
    for (int i = 0; i < 2; i++) {
        o.emplace_back(12, a[1]);
        o.emplace_back(3, a[1]);
        o.emplace_back(5, a[2]);
        o.emplace_back(10, a[2]);
    }
    o.emplace_back(15, a[3]);

    vector<array<i64, 16>> dp(1 << 16);
    for (auto &arr : dp) {
        arr.fill(inf);
    }
    dp[0][15] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, 15);

    vector vis(1 << 16, vector<bool>(16));
    vis[0][15] = true;

    while (not q.empty()) {
        auto [cur, x] = q.top();
        q.pop();

        for (auto [val, cost] : o) {
            int y = x xor val;
            auto nxt = cur | (1 << y);
            if (vis[nxt][y]) {
                continue;
            }

            if (dp[cur][x] + cost < dp[nxt][y]) {
                dp[nxt][y] = dp[cur][x] + cost;
                q.emplace(nxt, y);
            }
        }
    }

    vector<i64> f(1 << 16, inf);
    for (u32 s = 0; s < 1 << 16; s++) {
        for (int i = 0; i < 16; i++) {
            chmin(f[s], dp[s][i]);
        }
    }
    
    for (int i = 0; i < 16; i++) {
        for (u32 s = 0; s < 1 << 16; s++) {
            if (!(s >> i & 1)) {
                chmin(f[s], f[s ^ (1 << i)]);
            }
        }
    }

    while (T--) {
        int m;
        cin >> m;

        int sum = 0;
        for (int i = 0; i < m; i++) {
            char c;
            int cur = 0;
            for (int i = 0; i < 4; i++) {
                cin >> c;
                if (c == '1') {
                    cur |= 1 << i;
                }
            }
            sum |= 1 << cur;
        }

        cout << f[sum] << "\n";
    }

    return 0;
}