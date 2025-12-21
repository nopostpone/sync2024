#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct Point {
    i128 x, y;
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
i128 dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
i128 cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

int syn(const Point &a) {
    return a.y < 0 or (a.y == 0 and a.x > 0) ? 1 : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        i64 x, y;
        cin >> x >> y;
        a[i] = Point(x, y);
    }

    vector<int> ord;
    for (int i = 0; i < n; i++) {
        if (a[i] != Point(0, 0)) {
            ord.push_back(i);
        }
    }

    ranges::sort(ord, [&](int i, int j) {
        if (syn(a[i]) != syn(a[j])) {
            return syn(a[i]) == 1;
        }
        return cross(a[i], a[j]) > 0;
    });

    for (int i = 0; i < n; i++) {
        cout << ord[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
