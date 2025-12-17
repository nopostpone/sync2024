#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int P = 998244353;

int power(int a, i64 b) {
    int res = 1 % P;
    for (; b; b /= 2, a = (i64)a * a % P) {
        if (b & 1) {
            res = (i64)res * a % P;
        }
    }
    return res;
}
int inv(int x) {
    return power(x, P - 2);
}

int norm(int x) {
    if (x >= P) {
        x -= P;
    }
    if (x < 0) {
        x += P;
    }
    return x;
}
void add(int &x, int y) {
    x = norm(x + y);
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (i64)fac[i - 1] * i % P;
    }
    invfac[n] = inv(fac[n]);
    for (int i = n; i >= 1; i--) {
        invfac[i - 1] = (i64)invfac[i] * i % P;
    }
    auto binom = [&](int n, int m) {
        if (n < m or m < 0) {
            return 0;
        }
        return int((i64)fac[n] * invfac[n - m] % P * invfac[m] % P);
    };

    int ans = 0;
    int cnt = 0;
    for (int r = 1, l = 0; r <= n; r++) {
        if (r < n and s[r] == '0') {
            continue;
        }
        
    }
    cout << ans << "\n";
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