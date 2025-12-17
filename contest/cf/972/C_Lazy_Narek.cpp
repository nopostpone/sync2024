#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr string P = "narek";
constexpr char nxt(char c) {
    int x = P.find(c);
    return P[(x + 1) % 5];
}

constexpr bool check(char now, char tar) {
    if (P.find(now) == string::npos) {
        return false;
    }
    if (P.find(tar) == string::npos) {
        return false;
    }
    return true;
}
map<char, int> f;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];

    vector score(n + 1, vector<int>(5));
    vector ed(n + 1, vector<char>(5));

    for (int i = 1; i <= n; i++) {
        for (char c : P) {
            char now = c;
            for (auto j : S[i - 1]) {
                if (j == now) {
                    if (j == 'k') {
                        score[i][f[c]] += 5;
                    }
                    now = nxt(now);
                } else if (check(j, now)) {
                    score[i][f[c]]--;
                }
            }
            ed[i][f[c]] = now;
        }
    }

    vector dp(n + 1, vector<int>(5, -1e9));
    dp[1][f['n']] = 0;
    char c0 = ed[1][f['n']];
    dp[1][f[c0]] = score[1][f['n']];
    for (int i = 2; i <= n; i++) {
        for (char ch : P) {
            int j = f[ch]; // 我要找什么
            int k = f[ed[i][j]]; // 找 j，结尾的后继就是 k
            dp[i][k] = max(dp[i][k], dp[i - 1][j] + score[i][j]); // 拿
            dp[i][j] = max(dp[i][j], dp[i - 1][j]); // 不拿
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    f['n'] = 0;
    f['a'] = 1;
    f['r'] = 2;
    f['e'] = 3;
    f['k'] = 4;

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}