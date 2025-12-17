#include <bit/stdc++.h>
using i64 = long long;

// Point
// Try to avoid using floating-point numbers.
struct Point {
    i64 x;
    i64 y;

    Point operator-() const {
        return Point(-x, -y);
    }
};

// Basic Point Operations
Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}
Point operator-(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}
Point operator*(i64 a, Point b) {
    return Point(a * b.x, a * b.y);
}
Point operator*(Point a, i64 b) {
    return b * a;
}
bool operator==(Point a, Point b) {
    return a.x == b.x and a.y == b.y;
}

i64 dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
i64 cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
i64 square(const Point &p) {
    return dot(p, p);
}
double length(const Point &p) {
    return std::sqrt(square(p));
}

// Division -> Floating Type Needed
Point operator/(Point a, double b) {
    return Point(a.x / b, a.y / b);
}
// Direction vector
Point normalize(Point p) {
    return p / length(p);
}

struct Line {
    Point a;
    Point b;
};

// Line Operations
double length(const Line &l) {
    return length(l.a - l.b);
}
bool parallel(const Line &l1, const Line &l2) {
    return cross(l1.b - l1.a, l2.b - l2.a) == 0;
}

double distance(const Point &a, const Point &b) {
    return length(a - b);
}
// NEED FLOATING
// Point to Line
double distancePL(const Point &p, const Line &l) {
    return std::abs(cross(l.a - l.b, l.a - p)) / length(l);
}
// Point to Segment
double distancePS(const Point &p, const Line &l) {
    if (dot(p - l.a, l.b - l.a) < 0) {
        return distance(p, l.a);
    }
    if (dot(p - l.b, l.a - l.b) < 0) {
        return distance(p, l.b);
    }
    return distancePL(p, l);
}

// Counterclockwise 90 deg
Point rotate(const Point &a) {
    return Point (-a.y, a.x);
}

int sgn(const Point &a) {
    return a.y > 0 or (a.y == 0 and a.x > 0) ? 1 : -1;
}
bool pointOnLineLeft(const Point &p, const Line &l) {
    return cross(l.b - l.a, p - l.a) > 0;
}

Point lineIntersection(const Line &l1, const Line &l2) {
    return l1.a + (l1.b - l1.a) * (cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b));
}
// Includes endpoints
bool pointOnSegment(const Point &p, const Line &l) {
    return cross(p - l.a, l.b - l.a) == 0 and std::min(l.a.x, l.b.x) <= p.x and p.x <= std::max(l.a.x, l.b.x)
        and std::min(l.a.y, l.b.y) <= p.y and p.y <= std::max(l.a.y, l.b.y);
}
// O(n)
// Do not use this method if the polygon is a convex hull.
bool pointInPolygon(const Point &a, const std::vector<Point> &p) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (pointOnSegment(a, Line(p[i], p[(i + 1) % n]))) {
            return true;
        }
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        if (u.x < a.x and v.x >= a.x and pointOnLineLeft(a, Line(v, u))) {
            t ^= 1;
        }
        if (u.x >= a.x and v.x < a.x and pointOnLineLeft(a, Line(u, v))) {
            t ^= 1;
        }
    }
    return t == 1;
}

// 0 : not intersect
// 1 : strictly intersect
// 2 : overlap
// 3 : intersect at endpoint
std::tuple<int, Point, Point> segmentIntersection(const Line &l1, const Line &l2) {
    if (std::max(l1.a.x, l1.b.x) < std::min(l2.a.x, l2.b.x)) {
        return {0, Point(), Point()};
    }
    if (std::min(l1.a.x, l1.b.x) > std::max(l2.a.x, l2.b.x)) {
        return {0, Point(), Point()};
    }
    if (std::max(l1.a.y, l1.b.y) < std::min(l2.a.y, l2.b.y)) {
        return {0, Point(), Point()};
    }
    if (std::min(l1.a.y, l1.b.y) > std::max(l2.a.y, l2.b.y)) {
        return {0, Point(), Point()};
    }
    if (cross(l1.b - l1.a, l2.b - l2.a) == 0) {
        if (cross(l1.b - l1.a, l2.a - l1.a) != 0) {
            return {0, Point(), Point()};
        } else {
            auto maxx1 = std::max(l1.a.x, l1.b.x);
            auto minx1 = std::min(l1.a.x, l1.b.x);
            auto maxy1 = std::max(l1.a.y, l1.b.y);
            auto miny1 = std::min(l1.a.y, l1.b.y);
            auto maxx2 = std::max(l2.a.x, l2.b.x);
            auto minx2 = std::min(l2.a.x, l2.b.x);
            auto maxy2 = std::max(l2.a.y, l2.b.y);
            auto miny2 = std::min(l2.a.y, l2.b.y);
            Point p1(std::max(minx1, minx2), std::max(miny1, miny2));
            Point p2(std::min(maxx1, maxx2), std::min(maxy1, maxy2));
            if (!pointOnSegment(p1, l1)) {
                std::swap(p1.y, p2.y);
            }
            if (p1 == p2) {
                return {3, p1, p2};
            } else {
                return {2, p1, p2};
            }
        }
    }
    auto cp1 = cross(l2.a - l1.a, l2.b - l1.a);
    auto cp2 = cross(l2.a - l1.b, l2.b - l1.b);
    auto cp3 = cross(l1.a - l2.a, l1.b - l2.a);
    auto cp4 = cross(l1.a - l2.b, l1.b - l2.b);
    if ((cp1 > 0 and cp2 > 0) or (cp1 < 0 and cp2 < 0) or (cp3 > 0 and cp4 > 0) or (cp3 < 0 and cp4 < 0)) {
        return {0, Point(), Point()};
    }
    Point p = lineIntersection(l1, l2);
    if (cp1 != 0 and cp2 != 0 and cp3 != 0 and cp4 != 0) {
        return {1, p, p};
    } else {
        return {3, p, p};
    }
}

double distanceSS(const Line &l1, const Line &l2) {
    if (std::get<0>(segmentIntersection(l1, l2)) != 0) {
        return 0.0;
    }
    return std::min({distancePS(l1.a, l2), distancePS(l1.b, l2), distancePS(l2.a, l1), distancePS(l2.b, l1)});
}