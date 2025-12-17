#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};
int f[17] {};
int pw[30] {};

constexpr i64 lim = 1ll << 32;

// using B = bitset<32>;

constexpr int get(i64 s, int n) {
    // B b(s);
    
    auto ans = s >> (4 * n);
    return ans & 15;
}

void solve() {
    int n;
    i64 m;

    cin >> dec >> n;
    cin >> hex >> m;

    auto work = [&](i64 x) {

        if (x == lim) {
            // cerr << (i64)f[16] * (1 << 28) * 8 << endl;
            return (i64)f[16] * (1 << 28) * 8;
        }
        i64 res = 0;

        i64 sum = 0;
        for (int i = 7; i >= 0; i--) {
            auto cur = get(x, i);
            res += i64(f[cur] + sum * cur) * pw[4 * i];

            // cerr << i << " " << i64(f[cur] + sum * cur) << " " << pw[4 * i] << endl;
            if (i) {
                // cerr << (i64)f[16] * cur * pw[4 * (i - 1)] * i << endl;
                res += (i64)f[16] * cur * pw[4 * (i - 1)] * i;
            }
            sum += cost[cur];
        }
        // cerr << "\t" << x << " " << res << endl;
        return res;
    };

    // work(m);

    // cerr << m + n << endl;

    if (m + n <= lim) {
        cout << work(m + n) - work(m) << "\n";
    } else {
        cout << work(lim) - work(m) + work(m + n - lim) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    pw[0] = 1;
    for (int i = 1; i < 30; i++) {
        pw[i] = pw[i - 1] * 2;
    }

    for (int i = 0; i < 16; i++) {
        f[i + 1] = f[i] + cost[i];
    }

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

