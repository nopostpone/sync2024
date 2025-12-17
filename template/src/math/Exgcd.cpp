// ax + by = gcd(a, b)
// if a != 0, b != 0 then -b <= x <= b, -a <= y <= a
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

// {x, mod} -> {_, inv(x)}
constexpr std::pair<i64, i64> invGcd(i64 a, i64 b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    if (a == 0) {
        return {b, 0};
    }
    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;
    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        std::swap(s, t);
        std::swap(m0, m1);
    }
    if (m0 < 0) {
        m0 += b / s;
    }
    return {s, m0};
}