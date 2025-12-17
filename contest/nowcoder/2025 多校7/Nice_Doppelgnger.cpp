#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int N = 1e6;
bool bad[N + 1];

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

    int cnt = 0;
    vector<int> a;
    for (int x = 1; x <= n; x++) {
        if (cnt == n / 2) {
            break;
        }
        if (bad[x]) {
            continue;
        }
        cnt++;
        cout << x << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(N);
    bad[1] = true;
    for (int x = 2; x <= N; x++) {
        int cur = x;
        int cnt = 0;
        while (cur != 1) {
            cur /= minp[cur];
            cnt++;
        }
        if (cnt % 2 == 0) {
            bad[x] = true;
        }
    }

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}