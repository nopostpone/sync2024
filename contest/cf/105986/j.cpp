#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1e5);

    int n;
    cin >> n;

    vector<int> a(n + 1);

    auto it = lower_bound(primes.begin(), primes.end(), 1000);
    for (int i = 1; i <= n; i++) {
        a[i] = *it * i;
        it++;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}
