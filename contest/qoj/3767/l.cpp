#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
i64 mul(i64 a, i64 b, i64 m) {
    return static_cast<__int128>(a) * b % m;
}

i64 power(i64 a, i64 b, i64 m) {
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1)
            res = mul(res, a, m);
    return res;
}

bool isprime(i64 n) {
    if (n < 2) {
        return false;
    }
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    i64 d = (n - 1) >> s;
    for (auto a : A) {
        if (a == n) {
            return true;
        }
        i64 x = power(a, d, n);
        if (x == 1 or x == n - 1) {
            continue;
        }
        bool ok = false;
        for (int i = 0; i < s - 1; ++i) {
            x = mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return false;
        }
    }
    return true;
}

std::vector<i64> factorize(i64 n) {
    std::vector<i64> p;
    [&](this auto &&self, i64 n) -> void {
        if (n <= 10000) {
            for (int i = 2; i * i <= n; i++) {
                for (; n % i == 0; n /= i) {
                    p.push_back(i);
                }
            }
            if (n > 1) {
                p.push_back(n);
            }
            return;
        }
        if (isprime(n)) {
            p.push_back(n);
            return;
        }
        auto g = [&](i64 x) {
            return (mul(x, x, n) + 1) % n;
        };
        i64 x0 = 2;
        while (true) {
            i64 x = x0;
            i64 y = x0;
            i64 d = 1;
            i64 power = 1, lam = 0;
            i64 v = 1;
            while (d == 1) {
                y = g(y);
                ++lam;
                v = mul(v, std::abs(x - y), n);
                if (lam % 127 == 0) {
                    d = std::gcd(v, n);
                    v = 1;
                }
                if (power == lam) {
                    x = y;
                    power *= 2;
                    lam = 0;
                    d = std::gcd(v, n);
                    v = 1;
                }
            }
            if (d != n) {
                self(d);
                self(n / d);
                return;
            }
            ++x0;
        }
    } (n);

    std::sort(p.begin(), p.end());
    return p;
}

void solve()  {
    i64 a, b;
    int q;
    std::cin >> a >> b >> q;

    bool swapped = false;
    if (a > b) {
        swapped = true;
        std::swap(a, b);
    }

    i64 diff = b - a;

    if (diff == 0) {
        for (int i = 0; i < q; i++) {
            i64 k;
            std::cin >> k;

            std::cout << 1 << " " << 1 << "\n";
        }
        return;
    }
    std::map<i64, int> pf;
    int cnt = 0;

    {
        i64 td = diff;
        auto fac = factorize(diff);
    
        for (auto x : fac) {
            while (td % x == 0) {
                td /= x;
                pf[x]++;
                cnt++;
            }
        }
        if (td != 1) {
            pf[td]++;
            cnt++;
        }
    }

    i64 x = a;
    i64 cur = 0;
    std::vector<std::array<i64, 3>> events {{0, diff, x}};
    while (cnt > 0) {
        i64 m = 1e18;
        for (auto [x1, y] : pf) {
            if (y == 0) {
                continue;
            }
            m = std::min(m, x1 - x % x1);
        }
        x += m;
        cur += m;
        for (auto &[x1, y] : pf) {
            while (x % x1 == 0 and diff % x1 == 0) {
                diff /= x1;
                x /= x1;
                y--;
                cnt--;
            }
        }
        events.push_back({cur, diff, x});
    }

    i64 max = 1e18;
    for (int _ = 0; _ < q; _++) {
        i64 k;
        std::cin >> k;

        auto [t, d, x] = *std::prev(std::upper_bound(events.begin(), events.end(), {k, max, max}));

        x += k - t;

        i64 a = x;
        i64 b = x + d;
        if (swapped) {
            std::swap(a, b);
        }
        std::cout << a << " " << b << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}

/*
3
1 7 3
1
2
3
1 1 1
1
13 3 3
7
2
10
*/