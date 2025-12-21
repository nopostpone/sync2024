#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct Point {
    i64 x, y;
};
struct Line {
    Point a {}, b {};
};

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}
Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}
i64 dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
i64 cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
i64 square(const Point &a) {
    return a.x * a.x + a.y * a.y;
}
double length(const Point &a) {
    return sqrt(square(a));
}

i64 get(const Point &p, const Line &l) {
    return cross(l.b - l.a, p - l.a);
}
bool pointInConvex(const Point &a, const vector<Point> &p) {
    int n = p.size();
    if (get(a, Line(p[0], p[1])) < 0) {
        return false;
    }
    if (get(a, Line(p[0], p[n - 1])) > 0) {
        return false;
    }
    
    int lo = 1, hi = n;
    while (lo < hi) {
        int x = (lo + hi) / 2;
        if (get(a, Line(p[0], p[x])) <= 0) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    if (lo == 1) {
        return square(a - p[0]) <= square(p[1] - p[0]);
    }
    return get(a, Line(p[lo - 1], p[lo])) >= 0;
}

vector<Point> convexHull(vector<Point> a) {
    int n = a.size();
    if (n <= 1) {
        return a;
    }

    sort(a.begin(), a.end(),
        [&](auto a, auto b) {
            return a.x < b.x or (a.x == b.x and a.y < b.y);
        });
    
    vector<Point> h;

    for (int i = 0; i < n; i++) {
        while (h.size() >= 2 and cross(h[h.size() - 2] - a[i], h.back() - a[i]) <= 0) {
            h.pop_back();
        }
        h.push_back(a[i]);
    }

    int k = h.size();
    for (int i = n - 2; i >= 0; i--) {
        while (h.size() >= k + 1 and cross(h[h.size() - 2] - a[i], h.back() - a[i]) <= 0) {
            h.pop_back();
        }
        h.push_back(a[i]);
    }

    h.pop_back();
    return move(h);
}

vector<Point> minkowski(const vector<Point> &a, const vector<Point> &b) {
    int n = a.size(), m = b.size();
    if (n == 0 or m == 0) {
        return {};
    }

    vector<Point> c{a[0] + b[0]};
    int i = 0, j = 0;
    while (i < n and j < m) {
        auto va = a[(i + 1) % n] - a[i];
        auto vb = b[(j + 1) % m] - b[j];

        auto v = cross(va, vb);
        if (v > 0) {
            c.push_back(c.back() + va);
            i++;
        } else if (v < 0) {
            c.push_back(c.back() + vb);
            j++;
        } else {
            c.push_back(c.back() + va + vb);
            i++;
            j++;
        }
    }
    while (i < n) {
        c.push_back(c.back() + a[(i + 1) % n] - a[i]);
        i++;
    }
    while (j < m) {
        c.push_back(c.back() + b[(j + 1) % m] - b[j]);
        j++;
    }
    c.pop_back();

    return move(c);
}

i64 area(const vector<Point> &p) {
    i64 res = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        res += cross(p[i], p[(i + 1) % n]);
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Point> a(n), b(m);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }
    for (auto &[x, y] : b) {
        cin >> x >> y;
        x = -x;
        y = -y;
    }
    a = convexHull(a);
    b = convexHull(b);

    auto c = minkowski(a, b);

    i64 num = area(a) * area(b);
    i64 den = 2 * area(c);

    cout << (double)num / den << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

/*
2
3 3
0 0
1 0
0 1
0 0
1 0
0 1
3 3
0 0
1 0
0 1
0 1
1 0
1 1

1
3 4
7 6
6 7
-3 -9
8 -4
-9 -3
-5 -8
-3 -9
*/