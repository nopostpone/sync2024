// https://www.luogu.com.cn/problem/P4097
// 李超线段树 模板
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr double eps = 1e-9;

template <class T>
int cmp(T &a, T &b) {
    if (a - b > eps)
        return 1;
    if (b - a > eps)
        return -1;
    return 0;
}

struct line {
    double k;
    double b;
    function<double(int)> f = [&](int now) { return this->b + 1. * this->k * now; };
};

vector<line> t;
vector<int> s;

void addLine(int x0, int y0, int x1, int y1) {
    double k, b;
    if (x0 == y0) {
        k = 0;
        b = max(y0, y1);
    } else {
        k = 1. * (y1 - y0) / (1. * (x1 - x0));
        b = 1. * y0 - 1. * x0 * k; 
    }
    l.push_back(line{k, b});
}

void upd(int p, int l, int r, int u) {
    int v = s[p];
    int m = l + r >> 1;
    int bm = cmp(t[u].f(m), t[v].f(m));
    if (bm == 1 or (bm != 0 and u < v)) {
        swap(u, v);
    }
    int bl = cmp(t[u].f(l), t[v].f(l));
    int br = cmp(t[u].f(r), t[v].f(r));
    if (bl == 1 or (bl != 0 and u < v)) {
        upd(2 * p, l, m, u);
    } else if (br == 1 or (br != 0 and u < v)) {
        upd(2 * p + 1, m + 1, r, u);
    }
}

void upd(int p, int l, int r, int x, int y, int u) {
    if (x <= l and y <= r) {
        upd(p, l, r, u);
        return;
    }
    int m = l + r >> 1;
    if (x <= m)
        upd(2 * p, l, m, u);
    if (m < y)
        upd(2 * p + 1, m + 1, r, u);
    return;
}

int query(int p, int l, int r, int k) {
    if (l == r) {
        return id[p];
    }
    int m = l + r >> 1;
    double t
}

void solve() {
    int n;
    cin >> n;
    int lastans = 0;
    while(n--) {
        int op;
        cin >> op;
        if (op == 0) {
            int k;
            cin >> k;
            k = ((k + lastans - 1) % 39989) + 1;
        } else {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            x0 = ((x0 + lastans - 1) % 39989) + 1;
            x1 = ((x1 + lastans - 1) % 39989) + 1;
            y0 = ((y0 + lastans - 1) % 39989) + 1;
            y1 = ((y1 + lastans - 1) % 39989) + 1;
            addLine(x0, y0, x1, y1);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}