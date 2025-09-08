#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, inf);
    dp[0] = 0;

    int k = (n + 1) / 2;

    struct State {
        int x = 0;
        int y = 0;
        int lst = 0;
    };
    vector state(k, vector<State>(n));
    state[0][0].lst = -1;

    auto chmin = [&](auto &x, auto y, int i, int j, int a, int b) {
        if (y < x) {
            x = y;
            state[i][j] = {a, b, a};
        }
    };

    for (int i = 1; i < k; i++) {
        vector<int> ndp(n, inf);

        for (int j = 0; j < 2 * i - 1; j++) {
            ndp[j] = dp[j] + max(a[2 * i - 1], a[2 * i]);
            state[i][j] = {2 * i - 1, 2 * i, j};

            chmin(ndp[2 * i - 1], dp[j] + max(a[j], a[2 * i]), i, 2 * i - 1, j, 2 * i);
            chmin(ndp[2 * i], dp[j] + max(a[j], a[2 * i - 1]), i, 2 * i, j, 2 * i - 1);
        }

        dp = move(ndp);
    }

    int ans = inf;
    vector<int> seq;
    int p = -1;

    if (n % 2) {
        for (int i = 0; i < n; i++) {
            if (dp[i] + a[i] < ans) {
                p = i;
                ans = dp[i] + a[i];
            }
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            if (dp[i] + max(a[i], a[n - 1]) < ans) {
                p = i;
                ans = dp[i] + max(a[i], a[n - 1]);
            }
        }
        seq.push_back(n - 1);
    }
    seq.push_back(p);
    
    for (int cur = k - 1; cur > 0; cur--) {
        seq.push_back(state[cur][p].x);
        seq.push_back(state[cur][p].y);

        p = state[cur][p].lst;
    }
    reverse(seq.begin(), seq.end());

    cout << ans << "\n";
    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] + 1 << " \n"[i & 1];
    }

    return 0;
}