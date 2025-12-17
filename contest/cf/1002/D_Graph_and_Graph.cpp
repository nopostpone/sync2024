#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;

    s1--, s2--;

    vector adj1(n, vector<int>());
    int m1;
    cin >> m1;

    vector exi(n, vector<int>(n));

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        exi[u][v]++;
        exi[v][u]++;
    }

    vector adj2(n, vector<int>());
    int m2;
    cin >> m2;

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        exi[u][v]++;
        exi[v][u]++;
    }

    vector<bool> ed(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (exi[i][j] == 2) {
                ed[i] = true;
                ed[j] = true;
            }
        }
    }

    i64 ans = inf;

    vector dp(n, vector<i64>(n, inf));
    dp[s1][s2] = 0;

    queue<array<int, 2>> q;
    q.push({s1, s2});

    while (not q.empty()) {
        auto [u1, u2] = q.front();
        q.pop();

        for (auto v1 : adj1[u1]) {
            for (auto v2 : adj2[u2]) {
                if (v1 == v2 and ed[v1]) {
                    ans = min(ans, dp[u1][u2]);
                }
                int c = abs(v1 - v2);
                if (dp[u1][u2] + c < dp[v1][v2]) {
                    dp[v1][v2] = dp[u1][u2] + c;
                    q.push({v1, v2});
                }
            }
        }
    }
    
    if (ans == inf) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}