#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        if (m <= n) {
            return;
        }
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    Z fac(int m) {
        if (m > n)
            init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n)
            init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n)
            init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) {
        if (n < m || m < 0)
            return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

int n;
int c[26];
Z coef, ans;

int prec[27];

void solve() {
    n = 0;
	ans = 0, coef = 0;
    prec[0] = 0;

   	for (int i = 0; i < 26; i++) {
   		cin >> c[i];
   		n += c[i];
	}
    for (int i = 0; i < 26; i++) {
        prec[i + 1] = prec[i] + c[i];
    }

	for (int i = 0; i < 26; i++) {
		coef += (c[i] == 1);
	}
    coef = comb.fac(coef.val());
    for (int i = 0; i < 26; i++) {
        if (c[i] >= 2) {
            coef *= comb.invfac(c[i]);
        }
    }
    vector<int> dp(prec[26] + 1);
    dp[0] = 1;
    for (int i = 0; i < 26; i++) {
        for (int j = prec[26]; j >= c[i]; j--) {
            dp[j] += dp[j - c[i]];
        }
    }
    for (int i = 1; i <= prec[26]; i++) {
        int a = i;
        int b = prec[26] - i;
        if (a <= n / 2 and b <= (n + 1) / 2) {
            ans += comb.binom(n / 2, a) * comb.binom((n + 1) / 2, b) * comb.fac(a) * comb.fac(b);
        }
        if (b <= n / 2 and a <= (n + 1) / 2) {
            ans += comb.binom(n / 2, b) * comb.binom((n + 1) / 2, a) * comb.fac(a) * comb.fac(b);
        }
    }
    cout << ans * coef / 2 << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

	comb.init(5e5);
	
    int T;
    for (cin >> T; T--;) {
        solve();
    }


    return 0;
}
/*
3
3
1 2 3
3 2 1
5
4 5 3 1 2
4 5 1 3 2
7
4 3 1 2 7 5 6
1 2 3 4 5 6 7

1 2 3 
2 4 4 5 5 
4 4 4 4 7 7 7 

*/