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
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    sieve(n + 1);

    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (auto i : primes) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[n] << endl;

    return 0;
}