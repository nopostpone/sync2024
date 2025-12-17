#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> dp(1 << m);
    for (int i = 0; i < n; i++) {
        vector<int> ndp(1 << m, inf);

        for (int s1 = 0; s1 < (1 << m); s1++) {
            if (dp[s1] == inf) {
                continue;
            }
            for (int s2 = 0; s2 < (1 << m); s2++) {

                bool ok = true;
                for (int j = 0; j < m - 1; j++) {
                    int a1 = s1 >> j & 1;
                    int a2 = (s1 >> (j + 1)) & 1;
                    int b1 = s2 >> j & 1;
                    int b2 = (s2 >> (j + 1)) & 1;
                    if (a1 + a2 + b1 + b2 == 0) {
                        ok = false;
                    }
                }

                int cnt2 = 0;
                for (int j = 0; j < m; j++) {
                    if (s2 >> j & 1) {
                        if (s[i][j] == '#') {
                            cnt2++;
                        }
                    } else if (s[i][j] == '.') {
                        ok = false;
                    }
                }

                if (ok) {
                    ndp[s2] = min(ndp[s2], dp[s1] + cnt2);
                }
            }
        }

        dp = move(ndp);

        // for (int j = 0; j < 1 << m; j++) {
        //     cerr << (dp[j] == inf ? -1 : dp[j]) << " \n"[j + 1 == (1 << m)];
        // }

        // cerr << ranges::min(dp) << endl;
    }

    cout << ranges::min(dp) << "\n";
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