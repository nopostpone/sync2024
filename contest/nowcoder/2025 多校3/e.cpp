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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n % 2) {
        cout << "YES\n";
        return;
    }
    if (n == 2 and a[0] != a[1]) {
        cout << "NO\n";
        return;
    }

    map<int, int> f;
    for (auto x : a) {
        while (x != 1) {
            f[minp[x]]++;
            x /= minp[x];
        }
    }
    for (auto [d, c] : f) {
        if (c % 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(5e6);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}