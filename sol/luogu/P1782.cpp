#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace QuickRead {
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline int getc() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <typename T> void Cin(T &a) {
        T ans = 0;
        bool f = 0;
        char c = getc();
        for (; c < '0' || c > '9'; c = getc()) {
            if (c == '-') f = 1;
        }
        for (; c >= '0' && c <= '9'; c = getc()) {
            ans = ans * 10 + c - '0';
        }
        a = f ? -ans : ans;
    }
    template <typename T, typename... Args> void Cin(T &a, Args &...args) {
        Cin(a), Cin(args...);
    }
    template <typename T> void write(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
}

using namespace QuickRead;

int main() {
    int n, m, V;
    Cin(n, m, V);

    vector<array<ll, 2>> a;
    for (int i = 0; i < n; i++) {
        int v, w, d;
        Cin(v, w, d);
        for (int now = 1; d - now > 0; now *= 2) {
            a.push_back(array<ll, 2>{w * now, v * now});
            d -= now;
        }
        if (d > 0) {
            a.push_back(array<ll, 2>{w * d, v * d});
        }
    }

    vector b(m, vector<ll>(V + 1));
    for (int i = 0; i < m; i++) {
        int A, B, C;
        Cin(A, B, C);
        for (int j = 0; j <= V; j++) {
            b[i][j] = 1ll * A * j * j + B * j + C;
        }
    }

    vector<ll> bdp(V + 1);
    for (int i = 0; i < m; i++) {
        for (int j = V; ~j; j--) {
            for (int k = 0; k <= j; k++) {
                bdp[j] = max(bdp[j], bdp[j - k] + b[i][k]);
            }
        }
    }

    vector<ll> dp(V + 1);
    for (auto [w, v] : a) {
        for (int i = V; i >= v; i--) {
            dp[i] = max(dp[i], dp[i - v] + w);
        }
    }
    ll res = 0;
    for (int i = 0; i <= V; i++) {
        res = max(res, dp[i] + bdp[V - i]);
    }

    cout << res << endl;
    
    return 0;
}