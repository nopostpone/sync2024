#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct Point {
    i64 x;
    i64 y;
    Point() : x{0}, y{0} {}
    Point(i64 x_, i64 y_) : x{x_}, y{y_} {}
};

i64 dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

i64 cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

auto getHull(std::vector<Point> p) {
    std::sort(p.begin(), p.end(),
        [&](auto a, auto b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        });
    
    std::vector<Point> hi;
    vector<int> id;
    for (int i = 0; i < p.size(); i++) {
        while (hi.size() > 1 && cross(hi.back() - hi[hi.size() - 2], p[i] - hi.back()) >= 0) {
            hi.pop_back();
            id.pop_back();
        }
        while (!hi.empty() && hi.back().x == p[i].x) {
            id.pop_back();
            hi.pop_back();
        }
        hi.push_back(p[i]);
        id.push_back(i);
    }
    return std::make_pair(hi, id);
}

const double inf = INFINITY;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    // i64 ans = 1e18;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for (int k = 0; k < n; k++) {
    //             ans = min(ans, dot(a[i] - a[j], a[i] - a[k]));
    //         }
    //     }
    // }
    // cout << ans << "\n";


    auto [conv, id] = getHull(a);
    const int m = conv.size();

    vector<bool> vis(n);
    for (auto x : id) {
        vis[x] = true;
    }
    // cerr << id.size() << endl;
    
    // for (auto i : id) {
    //     cerr << i << ":\n";
    //     cerr << "(" << a[i].x << ", " << a[i].y << ")\n";
    // }
    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        
    }

    return 0;
}

/*
10
329463514 739825958
-128499293 -946420741
-209488913 249016048
980660790 -155959311
-411825439 649882452
-256324617 669454286
4033806 -619114232
647543026 -687225391
341624654 388863485
913139113 -228902181

-623690919509532380
*/