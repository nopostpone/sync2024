#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;

int get(u64 a) {
    u64 t = a;
    int res = 0;
    while (t != 1) {
        t = t * t;
        res++;
    }
    return res;
}

u64 power(u64 a, u64 n) {
    u64 res = 1;
    for (; n; n /= 2, a *= a) {
        if (n & 1) {
            res *= a;
        }
    }
    return res;
}

void solve() {
    u64 a, b;
    cin >> a >> b;

    if (b == 1 or (a % 2 != b % 2)) {
        cout << 0 << "\n";
        return;
    }

    if (a % 2 == 0) {
        u64 t = 1;
        for (int x = 0; x < 66; x++) {
            if (t == b) {
                cout << x << "\n";
                return;
            }
            t *= a;
        }
        cout << "broken message\n";
    } else {
        int r1 = get(a), r2 = get(b);
        if (r1 < r2) {
            cout << "broken message\n";
            return;
        }

        u64 ans = 0;
        auto ori = b;

        for (int _ = 0; _ < 65 and b != 1; _++) {
            int r3 = r1 - r2;
            if (r3 < 0)
                break;
            b = b * power(a, (1ull << r1) - (1ull << r3));
            ans += (1ull << r3);
            r2 = get(b);
        }

        ans %= (1ull << 63);
        if (power(a, ans) == ori) {
            cout << ans << "\n";
        } else {
            cout << "broken message\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

/*
5
2 4
3 27
1000000007 998244353
4 2
1000000007 1000000009
*/