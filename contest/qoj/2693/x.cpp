// Generated at 2026-01-25 16:13:50 UTC+8
// Created by Alphagocc
//  CCPC 2025 Jinan F
#ifndef UTIL_HPP
#define UTIL_HPP
#define _GLIBCXX_ASSERTIONS 1
#include <bits/stdc++.h>
#include <cstdint>
#define var auto
#define ALL(x) x.begin(), x.end()
#define If(x, y, z) ((x) ? (y) : (z))
using i128 = __int128_t;
using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
constexpr i32 INF = 0x3f3f3f3f;
constexpr i64 INFL = 0x3f3f3f3f3f3f3f3f;
#define FILEIO(x)                        \
    do {                                 \
        freopen(#x ".in", "r", stdin);   \
        freopen(#x ".out", "w", stdout); \
    } while (0)
#endif
#ifndef TYPE_HPP
#define TYPE_HPP
#include <type_traits>
#ifndef __cpp_lib_void_t
namespace std {
    template <typename...>
    using void_t = void;
}
#endif
template <typename T, typename _ = void>
struct is_container : std::false_type {};
template <typename... Ts>
struct is_container_helper {};
template <typename T>
struct is_container<T,
                    typename std::conditional<false,
                                              is_container_helper<decltype(std::declval<T>().size()),
                                                                  decltype(std::declval<T>().begin()),
                                                                  decltype(std::declval<T>().end())>,
                                              void>::type> : public std::true_type {};
#endif
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#define FI
// __inline__ __attribute__((always_inline))
class IO {
    static const int bufSize = 1 << 20;

    char inBuf[bufSize], outBuf[bufSize];
    char *ip1 = inBuf, *ip2 = inBuf;
    int goodReadBit = 1, op1 = -1, op2 = bufSize - 1;
    template <typename T>
    FI void __RI(T &x) {
        int ch = gc();
        x = 0;
        for (; !(isdigit(ch) || ch == '-' || ch == EOF); ch = gc()) {
        }
        if (ch == EOF) [[unlikely]]
            return;
        if (ch == '-') {
            ch = gc();
            for (; isdigit(ch); ch = gc())
                x = x * 10 + (48 - ch);
        } else {
            for (; isdigit(ch); ch = gc())
                x = x * 10 + (ch - 48);
        }
    }
    template <typename T>
    FI void __RC(T &x) {
        int ch;
        while (isspace(ch = gc())) {
        }
        if (ch == EOF)
            return;
        x = ch;
    }
    FI void __RS(std::string &x) {
        int ch;
        x.clear();
        for (ch = gc(); isspace(ch); ch = gc()) {
        }
        if (ch == EOF)
            return;
        for (; !isspace(ch) && ch != EOF; ch = gc())
            x.push_back(ch);
    }

public:
    FI int gc() {
        return ip1 == ip2 && (ip2 = (ip1 = inBuf) + fread(inBuf, 1, bufSize, stdin), ip1 == ip2)
                   ? (goodReadBit = 0, EOF)
                   : *ip1++;
    }
    FI IO &R(char &x) { return __RC(x), (*this); }
    FI IO &R(unsigned char &x) { return __RC(x), (*this); }
    FI IO &R(std::string &x) { return __RS(x), (*this); }
    template <typename T1, typename T2>
    FI IO &R(std::pair<T1, T2> &x) {
        return R(x.first, x.second), (*this);
    }
    template <typename T, typename... Args>
    FI IO &RA(T *a, int n) {
        for (int i = 0; i < n; ++i)
            R(a[i]);
        return (*this);
    }
    template <typename T, typename... Args>
    FI IO &R(T &x, Args &...args) {
        return R(x), R(args...), (*this);
    }
    template <typename T, typename... Args>
    FI IO &RA(T *a, int n, Args... args) {
        for (int i = 0; i < n; ++i)
            RA(a[i], args...);
        return (*this);
    }
    template <typename T>
    FI typename std::enable_if<std::is_integral<T>::value, IO>::type &R(T &x) {
        return __RI(x), (*this);
    }
    template <typename T>
    FI typename std::enable_if<is_container<T>::value, IO>::type &R(T &x) {
        for (auto &i : x)
            R(i);
        return (*this);
    }
    template <typename T>
    FI typename std::enable_if<std::is_void<std::void_t<decltype(std::declval<T>().read())>>::value,
                               IO>::type &
    R(T &x) {
        return x.read(), (*this);
    }

private:
    const char space = ' ';
    template <typename T>
    FI void __WI(T _x) {
        typename std::make_unsigned<T>::type x = _x;
        if (_x < 0)
            pc('-'), x = ~x + 1;
        static char buf[sizeof(T) * 16 / 5];
        static int len = -1;
        static constexpr char digits[201] = "0001020304050607080910111213141516171819"
                                            "2021222324252627282930313233343536373839"
                                            "4041424344454647484950515253545556575859"
                                            "6061626364656667686970717273747576777879"
                                            "8081828384858687888990919293949596979899";
        while (x >= 100) {
            auto num = (x % 100) * 2;
            x /= 100;
            buf[++len] = digits[num + 1];
            buf[++len] = digits[num];
        }
        if (x >= 10) {
            auto num = (x % 100) * 2;
            buf[++len] = digits[num + 1];
            buf[++len] = digits[num];
        } else {
            buf[++len] = '0' + x;
        }
        while (len >= 0) {
            pc(buf[len]), --len;
        }
    }

public:
    FI void pc(const char &x) {
        if (op1 == op2)
            flush();
        outBuf[++op1] = x;
    }
    FI void flush() { fwrite(outBuf, 1, op1 + 1, stdout), op1 = -1; }
    FI IO &W() { return (*this); }
    FI IO &W(const char &x) { return pc(x), (*this); }
    FI IO &W(const char *x) {
        while (*x != '\0')
            pc(*(x++));
        return (*this);
    }
    FI IO &W(const std::string &x) { return W(x.c_str()), (*this); }
    template <typename T1, typename T2>
    FI IO &W(const std::pair<T1, T2> &x) {
        W(x.first, x.second);
        return (*this);
    }
    FI IO &WL() { return W('\n'), (*this); }
    FI IO &WS() { return W(space), (*this); }
    template <typename T>
    FI IO &WA(T *a, int n) {
        for (int i = 0; i < n; i++)
            WS(a[i]);
        WL();
        return (*this);
    }
    template <typename T, typename... Args>
    FI IO &W(const T &x, const Args &...args) {
        W(x), W(space), W(args...);
        return (*this);
    }
    template <typename... Args>
    FI IO &WS(const Args &...args) {
        return W(args...), W(space), (*this);
    }
    template <typename... Args>
    FI IO &WL(const Args &...args) {
        return W(args...), W('\n'), (*this);
    }
    template <typename T, typename... Args>
    FI IO &WA(T *a, int n, Args... args) {
        for (int i = 0; i < n; i++)
            WA(a[i], args...);
        return (*this);
    }
    template <typename T>
    FI typename std::enable_if<std::is_integral<T>::value, IO>::type &W(const T &x) {
        return __WI(x), (*this);
    }
    template <typename T>
    FI typename std::enable_if<is_container<T>::value, IO>::type &W(const T &x) {
        for (const auto &i : x) {
            is_container<decltype(i)>::value ? W(i) : WS(i);
        }
        WL();
        return (*this);
    }
    template <typename T>
    FI typename std::enable_if<
        std::is_void<std::void_t<decltype(std::declval<T>().write())>>::value, IO>::type &
    W(const T &x) {
        return x.write(), (*this);
    }
    template <typename T>
    FI IO &operator>>(T &x) {
        R(x);
        return (*this);
    }
    template <typename T>
    FI IO &operator<<(const T &x) {
        W(x);
        return (*this);
    }
    int good() { return goodReadBit; }
    IO() {}
    ~IO() { flush(); }
} io;
#undef FI

using namespace std;

void solve() {
    int n;
    io >> n;
    vector<int> a(n), b(n);
    io >> a >> b;
    vector<pair<int, int>> segs;
    
    vector<int> type(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            type[i] = 1;
        } else if (a[i] + 1 == b[i]) {
            type[i] = 2;
        } else {
            type[i] = 3;
        }
    }


    for (int i = 0; i < n; i++) {
        // cerr << i << endl;
        if (a[i] == b[i] || a[i] + 1 == b[i]) {
            if (segs.empty() || segs.back().second != i || type[segs.back().first] != type[i] || (type[i] == 2 && (b[i - 1] < a[i] || a[i - 1] > b[i])) || (type[i] == 1 && a[i] != a[i - 1])) {
                segs.push_back({i, i + 1});
            } else {
                segs.back().second = i + 1;
            }
        } else {
            segs.push_back({i, i + 1});
        }
    }

    i64 ans = 0;
    for (int i = 0; i < segs.size(); i++) {
        auto [x, y] = segs[i];
        if (type[x] == 1)
            ans += i64(y - x) * (y - x);
        else if (type[x] == 3)
            ans++;
        else {
            int l = (i != 0 && type[segs[i - 1].first] == 1 ? segs[i - 1].first : -1);
            int r = (i != segs.size() - 1 && type[segs[i + 1].first] == 1 ? segs[i + 1].first
                                                                             : -1);
            int len = y - x;
            if (l == -1 || r == -1) {
                ans += len;
            } else {
                int ok = -1;
                int pre = a[x - 1];
                for (int i = x; i <= y; i++) {
                    if (pre != a[i] && pre != b[i]) {
                        ok = 1;
                        break;
                    } else if (pre == a[i])
                        pre = b[i];
                    else
                        pre = a[i];
                }
                if (ok == -1 && pre == a[y])
                    ok = 0;
                else
                    ok = 1;
                if (!ok) {
                    if (len == 1) {
                        int l1 = segs[i - 1].second - segs[i - 1].first;
                        int l2 = segs[i + 1].second - segs[i + 1].first;
                        int z;
                        if (l1 <= l2) {
                            z = l1;
                            ans += 2 * z + 1;
                        } else {
                            z = l2;
                            segs[i + 1].first--;
                            a[x] = b[x] = a[y];
                            type[x] = 1;
                        }
                    } else {
                        ans += len + 2;
                    }
                } else
                    ans += len;
            }
        }
    }
    io.WL(ans);
    return;
}
int main() {
    int T;
    io >> T;
    while (T--)
        solve();
    return 0;
}