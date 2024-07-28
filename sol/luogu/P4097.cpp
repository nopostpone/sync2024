// https://www.luogu.com.cn/problem/P4097
// 李超线段树 模板
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr double eps = 1e-9;

template <class T>
int cmp(const T &a, const T &b) {
    if (a - b > eps)
        return 1;
    if (b - a > eps)
        return -1;
    return 0;
}

struct line {
    double k;
    double b;
    inline double f(int now) { return this->b + 1. * this->k * now; }
};

vector<line> t;
vector<int> s;

void addLine(int x0, int y0, int x1, int y1, int cnt) {
    double k, b;
    if (x0 == x1) {
        k = 0;
        b = max(y0, y1);
    } else {
        k = 1. * (y1 - y0) / (1. * (x1 - x0));
        b = 1. * y0 - 1. * x0 * k;
    }
    t[cnt] = {k, b};
}

void inst(int p, int l, int r, int u) {
    int &v = s[p];
    int m = l + r >> 1;
    int bm = cmp(t[u].f(m), t[v].f(m));
    if (bm == 1 or (bm != 0 and u < v)) {
        swap(u, v);
    }
    int bl = cmp(t[u].f(l), t[v].f(l));
    int br = cmp(t[u].f(r), t[v].f(r));
    if (bl == 1 or (bl != 0 and u < v)) {
        inst(2 * p, l, m, u);
    } else if (br == 1 or (br != 0 and u < v)) {
        inst(2 * p + 1, m + 1, r, u);
    }
}

void upd(int p, int l, int r, int x, int y, int u) {
    if (x <= l and r <= y) {
        inst(p, l, r, u);
        return;
    }
    int m = l + r >> 1;
    if (x <= m)
        upd(2 * p, l, m, x, y, u);
    if (m < y)
        upd(2 * p + 1, m + 1, r, x, y, u);
    return;
}

pair<double, int> pmax(const pair<double, int> &A, const pair<double, int> &B) {
    if (cmp(A.first, B.first) == 1) {
        return A;
    } else if (cmp(A.first, B.first) == -1) {
        return B;
    } else {
        return A.second < B.second ? A : B;
    }
}

pair<double, int> query(int p, int l, int r, int k) {
    if (r < k or k < l) {
        return {0, 0};
    }
    int m = l + r >> 1;
    double res = t[s[p]].f(k);
    if (l == r) {
        return {res, s[p]};
    }
    return pmax({res, s[p]}, pmax(query(p * 2, l, m, k), query(p * 2 + 1, m + 1, r, k)));
}

#define endl "\n"

vector<int> res;
int cnt;

void solve() {
    int n;
    cin >> n;
    t.resize(100010, {});
    s.resize(40010 << 2, 0);
    int lastans = 0;

    while (n--) {
        bool op;
        cin >> op;
        if (!op) {
            int k;
            cin >> k;
            k = ((k + lastans - 1) % 39989) + 1;
            lastans = query(1, 1, 39989, k).second;
            res.push_back(lastans);
        } else {
            cnt++;
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            x0 = ((x0 + lastans - 1) % 39989) + 1;
            x1 = ((x1 + lastans - 1) % 39989) + 1;
            y0 = ((y0 + lastans - 1) % int(1e9)) + 1;
            y1 = ((y1 + lastans - 1) % int(1e9)) + 1;
            if (x0 > x1)
                swap(x0, x1), swap(y0, y1);
            addLine(x0, y0, x1, y1, cnt);
            upd(1, 1, 39989, x0, x1, cnt);
        }
    }

    for (auto i : res) 
        cout << i << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}