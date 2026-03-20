#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

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
    int x, y;
    cin >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    if (x == 1) {
        cout << -1 << "\n";
        return;
    }

    auto g = gcd(x, y);
    i64 ans = 1e18;
    if (g != 1) {
        ans = minp[g];
    }
    ans = min(ans, minp[x] == minp[y] ? minp[x] : (i64)minp[x] * minp[y]);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve(2e5);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}