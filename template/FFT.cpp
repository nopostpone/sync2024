#define x first
#define y second

template <class T>
struct Complex : public std::pair<T, T> {
    constexpr Complex(T x = T(), T y = T()) : std::pair<T, T>(x, y) {}

    constexpr Complex operator+(const Complex &a) const {
        return Complex(this->x + a.x, this->y + a.y);
    }
    constexpr Complex operator-(const Complex &a) const {
        return Complex(this->x - a.x, this->y - a.y);
    }
    constexpr Complex operator*(const Complex &a) const {
        return Complex(this->x * a.x - this->y * a.y, this->x * a.y + this->y * a.x);
    }
};
using ld = double;
using Comp = Complex<ld>;

constexpr ld pi = acosl(-1);

std::vector<Comp> w[2];
std::vector<int> r;

constexpr void init(int _log) {
    if (r.size() == (1 << _log))
        return;

    int n = 1 << _log;
    r.assign(n, 0);
    for (int i = 1; i < n; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (_log - 1));

    w[0].assign(n, Comp());
    w[1].assign(n, Comp());
    for (int i = 0; i < n; i++) {
        auto th = 1.L * pi * i / n;
        w[0][i] = Comp(cosl(th), sinl(th));
        w[1][i] = Comp(cosl(th), -sinl(th));
    }
}

void fft(std::vector<Comp> &a, int op) {
    int n = a.size();
    init(std::__lg(n));
    for (int i = 0; i < n; i++)
        if (i < r[i])
            std::swap(a[i], a[r[i]]);
    for (int mid = 1; mid < n; mid <<= 1) {
        const int d = n / mid;
        for (int R = mid << 1, j = 0; j < n; j += R) {
            for (int k = 0; k < mid; k++) {
                Comp x = a[j + k], y = w[op][d * k] * a[j + mid + k];
                a[j + k] = x + y;
                a[j + mid + k] = x - y;
            }
        }
    }
}

template <class T>
struct Polynomial : public std::vector<T> {
    explicit constexpr Polynomial(int n = 0, T v = T()) : std::vector<T>(n, v) {}
    explicit constexpr Polynomial(const std::vector<T> &a) : std::vector<T>(a) {}
    constexpr Polynomial(const std::initializer_list<T> &a) : std::vector<T>(a) {}

    template <class IT, class = std::_RequireInputIter<IT>>
    explicit constexpr Polynomial(IT first, IT last) : std::vector<T>(first, last) {}

    constexpr friend Polynomial operator*(const Polynomial &a, const Polynomial &b) {
        if (a.size() == 0 or b.size() == 0)
            return Polynomial();
        int n = a.size() + b.size() - 1;
        int _log = std::__lg(2 * n - 1);
        int s = 1 << _log;
        if (std::min(a.size(), b.size()) < 128) {
            Polynomial res(n);
            for (int i = 0; i < a.size(); i++)
                for (int j = 0; j < b.size(); j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        std::vector<Comp> p(s), q(s);
        for (int i = 0; i < a.size(); i++)
            p[i].x = a[i];
        for (int i = 0; i < b.size(); i++)
            q[i].x = b[i];

        fft(p, 0), fft(q, 0);
        for (int i = 0; i < s; i++)
            p[i] = p[i] * q[i];
        fft(p, 1);

        Polynomial res(n);
        for (int i = 0; i < n; i++)
            res[i] = p[i].x / s; // 默认浮点数
        return res;
    }
};

using Poly = Polynomial<ld>;
#undef x
#undef y