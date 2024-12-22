template <class T, class G>
struct BaseVector2 {
    T x, y;
    constexpr BaseVector2() : BaseVector2(T{}, T{}) {}
    constexpr BaseVector2(T x, T y) : x{x}, y{y} {}

    // 运算
    constexpr BaseVector2 operator+(BaseVector2 a) const {
        return BaseVector2(x + a.x, y + a.y);
    }
    constexpr BaseVector2 operator-(BaseVector2 a) const {
        return BaseVector2(x - a.x, y - a.y);
    }
    constexpr BaseVector2 operator-() const {
        return BaseVector2(-x, -y);
    }
    constexpr G operator*(BaseVector2 a) const {
        return G(x) * a.x + G(y) * a.y;
    }
    constexpr G operator%(BaseVector2 a) const {
        return G(x) * a.y - G(y) * a.x;
    }
    constexpr BaseVector2 rotate() const {
        return BaseVector2(-y, x);
    }
    template <class F>
    constexpr BaseVector2 rotate(F theta) const {
        BaseVector2 b(std::cos(theta), std::sin(theta));
        return BaseVector2(x * b.x - y * b.y,
                           x * b.y + y * b.x);
    }
    constexpr friend BaseVector2 operator*(const T &a, BaseVector2 b) {
        return BaseVector2(a * b.x, a * b.y);
    }

    // 比较
    constexpr bool operator<(BaseVector2 a) const {
        if (x == a.x) {
            return y < a.y;
        }
        return x < a.x;
    }

    constexpr bool operator>(BaseVector2 a) const {
        if (x == a.x) {
            return y > a.y;
        }
        return x > a.x;
    }

    constexpr bool operator<=(BaseVector2 a) const {
        if (x == a.x) {
            return y <= a.y;
        }
        return x <= a.x;
    }

    constexpr bool operator>=(BaseVector2 a) const {
        if (x == a.x) {
            return y >= a.y;
        }
        return x >= a.x;
    }

    constexpr bool operator==(BaseVector2 a) const {
        return x == a.x and y == a.y;
    }

    constexpr bool operator!=(BaseVector2 a) const {
        return x != a.x or y != a.y;
    }

    // 输入输出
    friend std::istream &operator>>(std::istream &in, BaseVector2 &p) {
        return in >> p.x >> p.y;
    }
    friend std::ostream &operator<<(std::ostream &ot, BaseVector2 p) {
        return ot << '(' << p.x << ", " << p.y << ')';
    }
};

template <class T, class G>
G dis2(BaseVector2<T, G> a, BaseVector2<T, G> b = BaseVector2<T, G>(0, 0)) {
    BaseVector2<T, G> p = a - b;
    return p * p;
}
template <class T, class G>
auto dis(BaseVector2<T, G> a, BaseVector2<T, G> b = BaseVector2<T, G>(0, 0)) {
    return std::sqrt(dis2(a, b));
}

template <class T, class G>
int sgn(BaseVector2<T, G> p) {
    if (p.x < 0 or p.x == 0 and p.y > 0) {
        return 1;
    } else
        return 0;
    // 以41象限为先
}

template <class Vector>
bool polarCmp(Vector p, Vector q) {
    if (sgn(p) == sgn(q)) {
        if (p % q == 0) {
            return dis2(p) < dis2(q);
        } else {
            return p % q > 0;
        }
    } else {
        return sgn(p) < sgn(q);
    }
}

using Point = BaseVector2<int, long long>;
using Vector = Point;
using PS = std::vector<Point>;