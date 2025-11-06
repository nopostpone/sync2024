    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;

    using ull = unsigned long long;
    using uint = unsigned int;
    template<typename T>
    constexpr T power(T a, ull b) {
        T res {1};
        for (; b != 0; b /= 2, a *= a) {
            if (b % 2 == 1) {
                res *= a;
            }
        }
        return res;
    }

    template<uint P>
    constexpr uint mulMod(uint a, uint b) {
        return 1ULL * a * b % P;
    }

    template<ull P>
    constexpr ull mulMod(ull a, ull b) {
        ull res = a * b - ull(1.L * a * b / P - 0.5L) * P;
        res %= P;
        return res;
    }

    template<typename U, U P>
    requires std::unsigned_integral<U>
    struct ModIntBase {
    public:
        constexpr ModIntBase() : x(0) {}

        template<typename T>
        requires std::integral<T>
        constexpr ModIntBase(T x_) : x(norm(x_ % T {P})) {}

        constexpr static U norm(U x) {
            if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
                x += P;
            }
            if (x >= P) {
                x -= P;
            }
            return x;
        }

        constexpr U val() const {
            return x;
        }

        constexpr ModIntBase operator-() const {
            ModIntBase res;
            res.x = norm(P - x);
            return res;
        }

        constexpr ModIntBase inv() const {
            return power(*this, P - 2);
        }

        constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
            x = mulMod<P>(x, rhs.val());
            return *this;
        }

        constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
            x = norm(x + rhs.x);
            return *this;
        }

        constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
            x = norm(x - rhs.x);
            return *this;
        }

        constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
            return *this *= rhs.inv();
        }

        friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
            lhs *= rhs;
            return lhs;
        }

        friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
            lhs += rhs;
            return lhs;
        }

        friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
            lhs -= rhs;
            return lhs;
        }

        friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
            lhs /= rhs;
            return lhs;
        }

        friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
            return os << a.val();
        }

        friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
            return lhs.val() == rhs.val();
        }

        friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
            return lhs.val() != rhs.val();
        }

        friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
            return lhs.val() < rhs.val();
        }

    private:
        U x;
    };

    template<uint P>
    using ModInt = ModIntBase<uint, P>;

    template<ull P>
    using ModInt64 = ModIntBase<ull, P>;

    constexpr uint P = 998244353;
    using Z = ModInt<P>;

    template <typename T>
    struct Fenwick {
        int n;
        std::vector<T> a;

        Fenwick(int n_ = 0) {
            init(n_);
        }

        void init(int n_) {
            n = n_;
            a.assign(n, T{});
        }

        void add(int x, const T &v) {
            for (int i = x + 1; i <= n; i += i & -i) {
                a[i - 1] = a[i - 1] + v;
            }
        }

        T ori(int x) {
            T ans{};
            for (int i = x; i > 0; i -= i & -i) {
                ans = ans + a[i - 1];
            }
            return ans;
        }

        T rangeSum(int l, int r) {
            return ori(r) - ori(l);
        }

        int select(const T &k) {
            int x = 0;
            T cur{};
            for (int i = 1 << std::__lg(n); i; i /= 2) {
                if (x + i <= n && cur + a[x + i - 1] <= k) {
                    x += i;
                    cur = cur + a[x - 1];
                }
            }
            return x;
        }
    };

    int main() {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n, k;
        cin >> n >> k;

        const Z E = Z(k) * (k - 1) / Z(4);

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        Fenwick<int> f(n);

        Z ori {};
        for (int i = 0; i < n; i++) {
            f.add(p[i], 1);
            ori += f.rangeSum(p[i] + 1, n);
        }

        Fenwick<int> g(n);

        Z now {};
        for (int i = 0; i < k; i++) {
            g.add(p[i], 1);
            now += g.rangeSum(p[i] + 1, n);
        }
        Z res(now);
        for (int i = k; i < n; i++) {
            g.add(p[i - k], -1);
            now -= g.rangeSum(0, p[i - k]);
            now += g.rangeSum(p[i], n);
            g.add(p[i], 1);

            res += now;
        }
        cout << ori - res / (n - k + 1) + E << endl;

        return 0;
    }
