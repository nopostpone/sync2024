#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

std::vector<int> minp, primes;

constexpr void sieve(int n) {
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
    
    sieve(1e5 + 1);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int win = 0;
    for (auto x : a) {
        if (x == 1) {
            continue;
        }
        int t = 0;
        for (auto i : primes) {
            while (x % i == 0 and x >= i) {
                t++;
                x /= i;
            }
            if (x == 1) {
                break;
            }
        }
        win ^= t;
    }

    cout << (win ? "Anna" : "Bruno");
    return 0;
}