#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int P = 998244353;

int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = (i64)a * a % P) {
        if (b % 2) {
            res = (i64)res * a % P;
        }
    }
    return res;
}

int work(i64 a, i64 b, i64 c, i64 d) {
    i64 g = __gcd(a, c);
    if (g == 1) {
        return 1;
    }
    int ans = power(g % P, min(b, d));
    if (b == d) {
        return ans;
    }

    i64 u = a / g;
    i64 v = c / g;

    if (b > d) {
        ans = 1ll * ans * work(g, b - d, v, d) % P;
    } else {
        ans = 1ll * ans * work(u, b, g, d - b) % P;
    }
    return ans;
}

mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << work(a, b, c, d) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}