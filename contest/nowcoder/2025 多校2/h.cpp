#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

namespace IO {
    FILE *Fin(stdin), *Fout(stdout);
    class qistream {
        static const size_t SIZE = 1 << 20, BLOCK = 32;
        FILE *fp;
        char buf[SIZE];
        int p;

    public:
        qistream(FILE *_fp = stdin) : fp(_fp), p(0) { fread(buf + p, 1, SIZE - p, fp); }
        void flush() { memmove(buf, buf + p, SIZE - p), fread(buf + SIZE - p, 1, p, fp), p = 0; }
        qistream &operator>>(char &str) {
            str = getch();
            while (isspace(str))
                str = getch();
            return *this;
        }
        template <class T>
        qistream &operator>>(T &x) {
            x = 0;
            p + BLOCK >= SIZE ? flush() : void();
            bool flag = false;
            for (; !isdigit(buf[p]); ++p)
                flag = buf[p] == '-';
            for (; isdigit(buf[p]); ++p)
                x = x * 10 + buf[p] - '0';
            x = flag ? -x : x;
            return *this;
        }
        char getch() { return buf[p++]; }
        qistream &operator>>(char *str) {
            char ch = getch();
            while (ch <= ' ')
                ch = getch();
            for (int i = 0; ch > ' '; ++i, ch = getch())
                str[i] = ch;
            return *this;
        }
    } qcin(Fin);
    class qostream {
        static const size_t SIZE = 1 << 20, BLOCK = 32;
        FILE *fp;
        char buf[SIZE];
        int p;

    public:
        qostream(FILE *_fp = stdout) : fp(_fp), p(0) {}
        ~qostream() { fwrite(buf, 1, p, fp); }
        void flush() { fwrite(buf, 1, p, fp), p = 0; }
        template <class T>
        qostream &operator<<(T x) {
            int len = 0;
            p + BLOCK >= SIZE ? flush() : void();
            x < 0 ? (x = -x, buf[p++] = '-') : 0;
            do
                buf[p + len] = x % 10 + '0', x /= 10, ++len;
            while (x);
            for (int i = 0, j = len - 1; i < j; ++i, --j)
                swap(buf[p + i], buf[p + j]);
            p += len;
            return *this;
        }
        qostream &operator<<(char x) {
            putch(x);
            return *this;
        }
        void putch(char ch) {
            p + BLOCK >= SIZE ? flush() : void();
            buf[p++] = ch;
        }
        qostream &operator<<(const char *str) {
            for (int i = 0; str[i]; ++i)
                putch(str[i]);
            return *this;
        }
    } qcout(Fout);
}
using namespace IO;

constexpr i64 inf = 1e18;

void solve() {
    int n, m;
    qcin >> n >> m;

    vector<vector<array<i64, 3>>> adj(n), radj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        i64 t;
        qcin >> u >> v >> t >> w;
        u--;
        v--;

        adj[u].push_back({v, t, w});
        radj[v].push_back({u, t, w});
    }

    vector<i64> f(n, inf);
    f[0] = 0;
    {
        priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> q;
        q.push({});
        while (not q.empty()) {
            auto [d, u] = q.top();
            q.pop();

            if (f[u] < d) {
                continue;
            }
            for (auto [v, t, _] : adj[u]) {
                if (f[u] + t < f[v]) {
                    f[v] = f[u] + t;
                    q.push({f[v], v});
                }
            }
        }
    }
    vector<i64> g(n, inf);
    g[n - 1] = 0;
    {
        priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> q;
        q.push({0, n - 1});
        while (not q.empty()) {
            auto [d, v] = q.top();
            q.pop();

            if (g[v] < d) {
                continue;
            }
            for (auto [u, t, _] : radj[v]) {
                if (g[v] + t < g[u]) {
                    g[u] = g[v] + t;
                    q.push({g[u], u});
                }
            }
        }
    }

    vector<pair<int, i64>> lines;
    for (int u = 0; u < n; u++) {
        for (auto [v, t, w] : adj[u]) {
            if (f[u] != inf and g[v] != inf) {
                lines.emplace_back(-w, f[u] + g[v] + t);
            }
        }
    }
    ranges::sort(lines, greater());

    vector<pair<int, i64>> hull;
    hull.emplace_back(0, f[n - 1]);

    for (auto [k, b] : lines) {
        while (hull.size() > 1) {
            int siz = hull.size();
            auto [k1, b1] = hull[siz - 2];
            auto [k2, b2] = hull[siz - 1];

            if (i128(b1 - b2) * (k2 - k) <= i128(b2 - b) * (k1 - k2)) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.emplace_back(k, b);
    }

    const int siz = hull.size();
    auto calc = [&](int i, int x) {
        auto [k, b] = hull[i];
        return (i64)k * x + b;
    };

    int q;
    qcin >> q;

    while (q--) {
        int k;
        qcin >> k;

        int lo = 0, hi = siz - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (calc(mid, k) < calc(mid + 1, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        qcout << calc(lo, k) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T;
    for (qcin >> T; T--;) {
        solve();
    }

    return 0;
}