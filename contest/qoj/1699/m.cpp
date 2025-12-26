// ref : jiangly https://qoj.ac/submission/769971
#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n >> b;
    
    i128 k = 0;
    {
        string s;
        cin >> s;

        for (auto c : s) {
            k = k * 10 + c - '0';
        }
        k--;
    }

    vector<int> p(n, -1), ip(n, -1);

    auto count = [&]() -> i128 {
        vector dp(n + 1, vector<i128>(b + 1));

        int base = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] != -1) {
                base += abs(p[i] - i);
            }
        }
        if (base > b) {
            return 0;
        }
        dp[0][base] = 1;
        for (int i = 0, cur = 0; i < n; i++) {
            if (p[i] == -1) {
                vector ndp(n + 1, vector<i128>(b + 1));
                for (int j = 0; j <= n; j++) {
                    for (int c = 0; c <= b; c++) {
                        if (dp[j][c] == 0) {
                            continue;
                        }
                        if (j + 1 <= n) {
                            ndp[j + 1][c] += dp[j][c];
                        }
                        ndp[j][c] += dp[j][c] * (j + cur);
                    }
                }
                dp = move(ndp);
                cur--;
            }
            if (ip[i] == -1) {
                vector ndp(n + 1, vector<i128>(b + 1));
                for (int j = 0; j <= n; j++) {
                    for (int c = 0; c <= b; c++) {
                        if (dp[j][c] == 0) {
                            continue;
                        }
                        ndp[j][c] += dp[j][c];
                        if (j != 0) {
                            ndp[j - 1][c] += dp[j][c] * j;
                        }
                    }
                }
                dp = move(ndp);
                cur++;
            }
            {
                vector ndp(n + 1, vector<i128>(b + 1));
                for (int j = 0; j <= n; j++) {
                    for (int c = 0; c <= b; c++) {
                        if (dp[j][c] == 0) {
                            continue;
                        }
                        auto nc = c + j + j + cur;
                        if (nc <= b) {
                            ndp[j][nc] += dp[j][c];
                        }
                    }
                }
                dp = move(ndp);
            }
        }
        return dp[0][b];
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ip[j] != -1) {
                continue;
            }

            p[i] = j;
            ip[j] = i;
            auto s = count();
            if (k < s) {
                break;
            }
            k -= s;
            p[i] = -1;
            ip[j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i + 1 == n];
    }

    return 0;
}

/*
30 300 3030303030303030303030
*/
