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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    auto h = convexHull(p);

    double ans = 0;
    for (int i = 0; i < h.size(); i++) {
        int j = (i + 1) % h.size();
        ans += length(h[i] - h[j]);
    }
    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}