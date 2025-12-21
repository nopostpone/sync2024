#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int P = 998244353;

constexpr int power(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = 1ll * a * a % P) {
        if (b & 1) {
            res = 1ll * res * a % P;
        }
    }
    return res;
}

void solve() {
    int k, m;
    cin >> k >> m;

    int ans = 1ll * k * power(m + 1, k - 1) % P;
    int t = 1ll * m * (m + 1) / 2 % P;

    ans = 1ll * ans * t % P;
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
}

/*
3
2 1
3 2
20250308 410338673
*/