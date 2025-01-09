#include <bits/stdc++.h>
using namespace std;
using ll = long long;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i < n; i++) {
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

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    unsigned l, r;
    cin >> l >> r;

    sieve(std::sqrt(r) + 1);

    vector<bool> p(r - l + 1);

    for (auto x : primes) {
        for (unsigned i = max(2u, l / x) * x; i <= r; i += x) {
            if (l <= i and i <= r) {
                p[i - l] = true;
            }
        }
    }

    int ans{};
    for (auto i : p) {
        ans += (not i);
    }
    cout << ans - (l == 1) << "\n";


    return 0;
}