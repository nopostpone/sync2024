#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    auto valid = [&](int i, int t) {
        if (i < 0) {
            return true;
        }
        for (int j = 0; j < m; j++) {
            if ((t >> j & 1) and s[i][j] == 'N') {
                return false;
            }
        }
        for (int j = 0; j < m - 1; j++) {
            if ((t >> j & 1) and (t >> (j + 1) & 1)) {
                return false;
            }
        }
        return true;
    };

    vector<int> dp(1 << m);
    for (int i = 0; i < n; i++) {
        vector<int> ndp(1 << m);

        for (int x = 0; x < 1 << m; x++) {
            if (not valid(i - 1, x)) {
                continue;
            }
            for (int y = 0; y < 1 << m; y++) {
                if (not valid(i, y)) {
                    continue;
                }
                bool bad = false;
                for (int j = 0; j < m; j++) {
                    if ((x >> j & 1) and (y >> j & 1)) {
                        bad = true;
                    }
                }
                if (not bad) {
                    ndp[y] = max(ndp[y], dp[x] + __builtin_popcount(y));
                }
            }
        }

        dp = move(ndp);
    }

    cout << ranges::max(dp) << "\n";

    return 0;
}