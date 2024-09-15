#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

constexpr string P = "narek";
map<char, int> f;

constexpr char nxt(const char &x) {
    int i = P.find(x);
    return P[(i + 1) % 5];
}
constexpr bool check(const char &x) {
    return P.find(x) != string::npos;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    vector<int> dp(5, -inf), ndp;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        ndp = dp;
        for (int j = 0; j < 5; j++) {
            if (dp[j] == -inf) {
                continue;
            }
            int t = 0;
            char now = P[j];

            for (auto c : S[i]) {
                if (not check(c)) {
                    continue;
                }

                if (now == c) {
                    t++;
                    now = nxt(now);
                } else {
                    t--;
                }
            }
            
            int k = f[now];
            ndp[k] = max(ndp[k], dp[j] + t);
        }
        dp = ndp;
    }

    for (int i = 0; i < 5; i++) {
        dp[i] -= 2 * i;
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
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