#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

std::vector<int> minp(1e8 + 1), primes;

void sieve(int n) {
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
    
    int n, q;
    cin >> n >> q;

    sieve(n);

    while (q--) {
        int x;
        cin >> x;
        cout << primes[x - 1] << endl;
    }
    
    return 0;
}