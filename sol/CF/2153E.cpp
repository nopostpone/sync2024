#pragma optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
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

auto get(int p, int x) {
    int ans = 0;
    for (i64 i = p; i <= x; i *= p) {
        ans += x / i;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int st = *prev(upper_bound(primes.begin(), primes.end(), n));
    vector<int> cand;
    for (int x = st; x <= n; x++) {
        int tem = x;
        while (tem != 1) {
            if (minp[tem] <= m) {
                cand.push_back(minp[tem]);
            }
            tem /= minp[tem];
        }
    }
    ranges::sort(cand);
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    int ans = 0;
    for (int x = st; x <= n - 1; x++) {
        int res = INT_MAX;
        for (auto p : cand) {
            int cntn = get(p, n);
            int cntx = get(p, x);

            int cntp = 0;
            for (i64 i = p; i <= m; i *= p) {
                cntp++;
                if (cntn / cntp != cntx / cntp) {
                    res = min(res, cntx / cntp);
                }
            }
        }
        ans += res;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1e7 + 1);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
