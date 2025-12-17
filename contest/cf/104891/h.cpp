#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int P = 998244353;
constexpr int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = i64(a) * a % P) {
        if (b & 1) {
            res = i64(res) * a % P;
        }
    }
    return res;
}
constexpr void add(int &x, int y) {
    x += y;
    if (x >= P) {
        x -= P;
    }
    if (x < 0) {
        x += P;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }
    vector<int> invfac(n + 1);
    invfac[n] = power(fac[n], P - 2);
    for (int i = n; i > 0; i--) {
        invfac[i - 1] = 1ll * invfac[i] * i % P;
    }

    auto binom = [&](int n, int m) -> int {
        if (n < m or m < 0) {
            return 0;
        }
        return 1ll * fac[n] * invfac[n - m] % P * invfac[m] % P;
    };

    vector<int> p(n);
    p[0] = -1;

    vector<vector<int>> adj(n);
    vector<int> dep(n);

    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);

        dep[i] = dep[p[i]] + 1;
    }
    
    vector<vector<int>> dp(n);
    vector<int> siz(n);
    [&](this auto &&self, int x) -> void {
        dp[x].assign(dep[x] + 2, 1);

        for (auto y : adj[x]) {
            self(y);
            vector<int> f(dep[x] + 2);

            for (int i = 0; i <= dep[x] + 1; i++) {
                for (int j = 0; j <= dep[y] and i + j <= dep[x] + 1; j++) {
                    int w = binom(siz[x] + siz[y] + i + j, siz[x] + i);

                    add(f[i + j], 1ll * dp[x][i] * dp[y][j] % P * w % P);
                }
            }

            dp[x] = move(f);
            siz[x] += siz[y];
        }
        dp[x].erase(dp[x].begin());
        siz[x]++;
    } (0);

    cout << dp[0][0] << endl;

    return 0;
}