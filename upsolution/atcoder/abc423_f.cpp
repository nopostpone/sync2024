#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    i64 V;
    cin >> V;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto safeLcm = [&](i64 x, i64 y) {
        i64 g = std::gcd(x, y);
        if (x / g > V / y) {
            return V + 1;
        }
        return x / g * y;
    };

    vector<i64> f(1 << n);
    for (u32 s = 1; s < (1 << n); s++) {
        i64 cur = 1;
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
                cur = safeLcm(cur, a[i]);
            }
        }
        f[s] = V / cur;
    }

    for (int i = 0; i < n; i++) {
        for (u32 s = 0; s < (1 << n); s++) {
            if (!(s >> i & 1)) {
                f[s] -= f[s | (1 << i)];
            }
        }
    }

    i64 ans = 0;
    for (u32 s = 0; s < (1 << n); s++) {
        if (__builtin_popcount(s) == m) {
            ans += f[s];
        }
    }
    cout << ans << "\n";

    return 0;
}