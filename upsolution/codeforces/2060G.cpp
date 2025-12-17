#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[i][j];
        }
    }

    ranges::sort(a, [](auto i, auto j) {
        return i[0] + i[1] < j[0] + j[1];
    });

    int dp[2][2]{}; // 总共翻转了奇偶次；当前位置是否反转
    dp[0][0] = true;
    dp[1][1] = true;

    for (int i = 1; i < n; i++) {
        int ndp[2][2]{};

        bool u = a[i][0] > a[i - 1][0] and a[i][1] > a[i - 1][1]; // 直接能对上
        bool v = a[i][1] > a[i - 1][0] and a[i][0] > a[i - 1][1]; // 翻转一下能对上

        if (u and v) {
            // 如果翻不翻都能对上：
            ndp[1][1] = ndp[0][0] = dp[0][0] | dp[0][1];
            ndp[0][1] = ndp[1][0] = dp[1][0] | dp[1][1];

        } else if (u) {
            // 如果仅不翻能对上：
            ndp[0][0] = dp[0][0];
            ndp[1][0] = dp[1][0];

            ndp[1][1] = dp[0][1];
            ndp[0][1] = dp[1][1];

        } else if (v) {
            // 如果仅翻转能对上：
            ndp[0][0] = dp[0][1];
            ndp[1][0] = dp[1][1];

            ndp[1][1] = dp[0][0];
            ndp[0][1] = dp[1][0];
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = ndp[i][j];
            }
        }
    }

    bool ok = dp[0][0] or dp[0][1];
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}