#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

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
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> fac;
    for (int t = x; t != 1;) {
        int p = minp[t];

        fac.push_back(p);
        while (t % p == 0) {
            t /= p;
        }
    }

    i64 ans = 0;
    for (auto d : fac) {
        i64 res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % d == 0) {
                res += a[i];
            }
        }
        ans = std::max(ans, res);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(3e5);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}