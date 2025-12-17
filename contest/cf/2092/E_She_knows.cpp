#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <class T>
constexpr T power(int a, T b, T p) {
    T res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

constexpr i64 P = 1000000007;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    auto corner = [&](int i, int j) {
        bool u = (i == 1 or i == n);
        bool v = (j == 1 or j == m);
        return u & v;
    };
    auto edge = [&](int i, int j) {
        return i == 1 or i == n or j == 1 or j == m;
    };

    int good = 0, sum = 0;
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        
        if (corner(x, y)) {
            continue;
        }
        if (edge(x, y)) {
            good += 1;
            sum += c;      
        }
    }
    int ans = 0;
    if (good == 2 * (n + m - 4)) {
        if (sum % 2 == 0) {
            ans = power(2, 1ll * n * m - k, P);
        }
    } else {
        ans = power(2, 1ll * n * m - k - 1, P);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}