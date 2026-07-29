#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int D = 202;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

void solve() {
    int l, r, n;
    std::cin >> l >> r >> n;

    std::vector<int> fac;

    for (int tn = n; tn != 1;) {
        int p = minp[tn];
        fac.push_back(p);
        while (tn % p == 0) {
            tn /= p;
        }
    }

    auto get = [&](int d) {
        i64 res = 0;
        for (int s = 0; s < 1 << fac.size(); s++) {
            i64 prod = 1;
            int cnt = 0;

            for (int i = 0; i < fac.size(); i++) {
                if (s >> i & 1) {
                    prod *= fac[i];
                    cnt++;
                }
            }
            if (cnt % 2) {
                res -= d / prod;
            } else {
                res += d / prod;
            }
        }
        return res;
    };

    i64 ans = 0;

    int m = std::max(l, n - D);

    if (m <= r) {
        int k = std::min(n - 1, D);
        std::vector<i64> dp(k + 1);

        for (int i = 1; i <= k; i++) {
            int x = n - i;
            dp[i] = std::__gcd(x, n);

            for (int j = 1; j < i; j++) {
                int y = n - j;

                dp[i] = std::min(dp[i], dp[j] + std::__gcd(x, y));
            }
            if (m <= x and x <= r) {
                ans += dp[i];
            }
        }
    }

    int mm = std::min(r, m - 1);
    if (l <= mm) {
        i64 tem = get(mm) - get(l - 1);
        ans += tem + 2 * (mm - l + 1 - tem);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(1e7);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
