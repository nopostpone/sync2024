#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

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

void solve(int n) {
    i64 m;
    qcin >> m;

    if (n == 1) {
        int l;
        qcin >> l;
        vector<int> a(l);
        for (int i = 0; i < l; i++) {
            qcin >> a[i];
        }
        i64 ans = accumulate(a.begin(), a.end(), 0ll);
        i64 cur = m;

        int need = 0;
        for (int i = 0; i < l; i++) {
            if (cur > a[i]) {
                ans -= a[i];
                need = max(need, a[i] + i + 1);
                cur--;
            } else if (cur == a[i]) {
                ans -= a[i];
                break;
            } else {
                // cerr << m << " " << need << endl;
                ans -= (m - need);
                if (i) {
                    ans--;
                }
                break;
            }
        }
        qcout << ans << "\n";

    } else {

        array<int, 2> l{};
        vector<vector<int>> a(n);
        for (int t = 0; t < n; t++) {
            qcin >> l[t];
            a[t].resize(l[t]);
            for (int i = 0; i < l[t]; i++) {
                qcin >> a[t][i];
            }
        }

        vector<vector<i64>> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i].resize(l[i] + 1);
            for (int j = 0; j < l[i]; j++) {
                pre[i][j + 1] = pre[i][j] + a[i][j];
            }
        }

        vector<i64> f[2]{vector<i64>(l[0] + 1), vector<i64>(l[1] + 1)};
        f[0][0] = f[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l[i]; j++) {
                f[i][j + 1] = max<i64>(f[i][j], a[i][j] + j + 1);
            }
        }

        i64 ans = 0;
        // for (int i = 0; i <= l[0]; i++) {
        //     if (i < l[0] and f[0][i] == f[0][i + 1]) {
        //         continue;
        //     }
        //     i64 u = pre[0][i];
        //     i64 r1 = m - f[0][i];

        //     int j = upper_bound(f[1].begin(), f[1].end(), r1) - f[1].begin() - 1;
        //     if (j >= 0) {

        //         i64 v = pre[1][j];
        //         i64 res = u + v;
        //         i64 r2 = r1 - f[1][j];

        //         if (i < l[0] and r2 + f[0][i] >= f[0][i + 1]) {
        //             continue;
        //         }
        //         if (i == l[0] and j == l[1]) {
        //             r2 = 0;
        //         }

        //         if (i and i < l[0]) {
        //             res++;
        //         }
        //         if (j and j < l[1]) {
        //             res++;
        //         }
        //         res += r2;
        //         ans = max(ans, res);
        //     }
        // }

        // for (int i = 0; i <= l[1]; i++) {
        //     if (i < l[1] and f[1][i] == f[1][i + 1]) {
        //         continue;
        //     }
        //     i64 u = pre[1][i];
        //     i64 r1 = m - f[1][i];

        //     int j = upper_bound(f[0].begin(), f[0].end(), r1) - f[0].begin() - 1;
        //     if (j >= 0) {

        //         i64 v = pre[0][j];
        //         i64 res = u + v;
        //         i64 r2 = r1 - f[0][j];
        //         if (i < l[1] and r2 + f[1][i] >= f[1][i + 1]) {
        //             continue;
        //         }
        //         if (i == l[1] and j == l[0]) {
        //             r2 = 0;
        //         }

        //         if (i and i < l[1]) {
        //             res++;
        //         }
        //         if (j and j < l[0]) {
        //             res++;
        //         }
        //         res += r2;
        //         ans = max(ans, res);
        //     }
        // }

        for (int i = 0; i <= l[0]; i++) {
            if (i < l[0] and f[0][i] == f[0][i + 1]) {
                continue;
            }
            for (int j = 0; j <= l[1]; j++) {
                if (j < l[1] and f[1][j] == f[1][j + 1]) {
                    continue;
                }

                i64 rest = m - f[0][i] - f[1][j];
                if (rest < 0) {
                    continue;
                }
                i64 res = pre[0][i] + pre[1][j];
                if (i and i < l[0]) {
                    res++;
                }
                if (j and j < l[1]) {
                    res++;
                }
                res += rest;
                // cerr << i << " " << j << " " << rest << " " << res << endl;
                ans = max(ans, res);
            }
        }

        ans = pre[0].back() + pre[1].back() - ans;
        ans = max(ans, 0ll);
        assert(ans >= 0 and ans <= max(0ll, pre[0].back() + pre[1].back() - m));
        qcout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n;
    for (qcin >> T >> n; T--;) {
        solve(n);
    }

    return 0;
}
