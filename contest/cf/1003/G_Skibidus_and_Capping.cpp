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

    vector<int> f(n + 1);

    i64 ans = 0;

    i64 cnt = 0;
    for (int i = 0; i < n; i++) {
        if (isprime(a[i])) {
            ans += cnt - f[a[i]];
            cnt++;
            f[a[i]]++;
        }
    }

    vector<int> g(n + 1);

    for (auto x : a) {
        if (isprime(x)) {
            continue;
        }
        int y = minp[x];
        int z = x / y;
        if (isprime(z)) {
            ans += f[y];
            if (y != z) {
                ans += f[z];
            }
            g[x]++;
            ans += g[x];
        }
    }
    
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    sieve(2e5);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}