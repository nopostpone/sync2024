#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

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

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

constexpr i64 mul(i64 a, i64 b, i64 m) {
    return i128(a) * b % m;
}

template <class T>
T power(int a, T b, T p) {
    T res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

bool isprime(i64 n) {
    if (n < 2) return false;
    if (n == 2 or n == 3 or n == 5 or n == 7) return true;
    if (n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0) return false;

    i64 d = n - 1;
    int s = 0;
    while (d % 2 == 1) {
        d /= 2;
        s++;
    }

    static const i64 bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    for (i64 a : bases) {
        if (a % n == 0) continue;
        i64 x = power(a, d, n);
        if (x == 1 or x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = mul(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

i64 factor(i64 n) {
    if (n <= 1) return n;
    if (n % 2 == 0) return 2;
    if (isprime(n)) return n;
    
    i64 m = 2;
    while (true) {
        i64 c = (rng() % (n - 1)) + 1;
        auto f = [&](i64 x) { return (mul(x, x, n) + c) % n; };
        i64 d = 1, x = m, y = m, p = 1, q = 0, v = 1;
        
        while (d == 1) {
            y = f(y);
            q++;
            v = mul(v, std::abs(x - y), n);
            
            if (q % 127 == 0) {
                d = std::gcd(v, n);
                v = 1;
            }
            if (p == q) {
                x = y;
                p *= 2;
                q = 0;
                d = std::gcd(v, n);
                v = 1;
            }
        }
        if (d != n) {
            return d;
        }
        m++;
    }
}

std::vector<i64> factorize(i64 n) {
    std::vector<i64> p;
    auto dfs = [&](auto &&self, i64 cur_n) -> void {
        if (cur_n <= 1) return;
        if (isprime(cur_n)) {
            p.push_back(cur_n);
            return;
        }
        i64 d = factor(cur_n);
        self(self, d);
        self(self, cur_n / d);
    };
    dfs(dfs, n);
    std::sort(p.begin(), p.end());
    return p;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(2e6);

    int n, q;
    std::cin >> n >> q;

    std::vector<u64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;

        adj[u].emplace_back(v, i - 1);
        adj[v].emplace_back(u, i - 1);
    }

    int cur = std::distance(primes.begin(), rgs::upper_bound(primes, 10000));

    std::vector<u64> d(n), f(n), sum(n);
    std::vector<int> w(n - 1);

    std::vector<int> g(primes.back() + 1);
    u64 f0 = 0;
    [&](this auto &&self, int x, int p) -> void {
        sum[x] = a[x];
        for (auto [y, id] : adj[x]) {
            if (y == p) {
                continue;
            }

            g[primes[cur]] = y;
            d[y] = primes[cur++];
            sum[x] += sum[y];
            self(y, x);

            w[id] = d[y] - d[x];
        }
        f0 += a[x] * d[x];
    } (0, -1);

    for (int i = 0; i < n - 1; i++) {
        std::cout << w[i] << " \n"[i + 1 == n - 1];
    }

    for (int _ = 0; _ < q; _++) {
        std::cout << "? 1 " << std::endl;
        u64 f1;
        std::cin >> f1;

        i64 r = f1 - f0;
        bool posti = true;
        if (r < 0) {
            r = -r;
            posti = false;
        }
        auto big = factorize(r).back();
        int x = g[big];

        i64 dv = r / big;
        i64 v = posti ? a[x] + dv : a[x] - dv;

        std::cout << "! " << x + 1 << " " << v << std::endl;
    }
}