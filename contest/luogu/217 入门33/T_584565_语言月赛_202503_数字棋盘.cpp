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

    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    cin >> a;

    int x, y;
    cin >> x >> y;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == x) {
                bool ok = false;
                if (i > 0 and a[i - 1][j] == y) {
                    ok = true;
                }
                if (i < n - 1 and a[i + 1][j] == y) {
                    ok = true;
                }
                if (j > 0 and a[i][j - 1] == y) {
                    ok = true;
                }
                if (j < m - 1 and a[i][j + 1] == y) {
                    ok = true;
                }
                ans += ok;
            }
        }
    }
    cout << ans << endl;


    return 0;
}