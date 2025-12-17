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

template <typename T>
istream& operator>>(istream &is, vector<T> &a) {
    for (auto &x : a) {
        is >> x;
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    sieve(n + 1);

    set<int> s;
    for (int i = 2; i <= n; i++) {
        int x = i * i;
        for (int d = 1; x * d <= n; d++) {
            s.insert(x * d);
        }
    }

    int ans = 0;
    int ans2 = 1e9;
    for (auto x : primes) {
        int y = n - x;
        if (s.find(y) != s.end()) {
            ans++;
            ans2 = min(ans2, abs(x - y));
        }
    }
    cout << ans << endl;
    cout << ans2 << endl;


    return 0;
}