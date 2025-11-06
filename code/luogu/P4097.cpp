// https://www.luogu.com.cn/problem/P4097
// 李超线段树 模板
#include <bits/stdc++.h>
using namespace std;

struct Line {
    double k = 0;
    double b = 0;
};

template <class Line>
struct LiChaoTree {
#define lst p << 1
#define rst p << 1 | 1
    const double eps = 1e-9;
    int n;
    int cnt;
    vector<int> s;
    vector<Line> l;
    
    LiChaoTree() {}

    LiChaoTree(int n_, int m_) {
        this->init(n_, m_);
    }

    void init(int n_, int m_) {
        this->n = n_;
        this->cnt = 0;
        s.resize(n << 2, 0);
        l.resize(m_ + 1, {});
    }

    template <class T>
    inline double f(int id, T now) {
        return 1. * l[id].k * now + l[id].b;
    }

    template <class T>
    inline int cmp(const T &x, const T &y) {
        if (x - y > eps)
            return 1;
        if (y - x > eps)
            return -1;
        return 0;
    }

    template<class T>
    void addLine(T x0, T y0, T x1, T y1) {
        if (x0 > x1)
            swap(x0, x1), swap(y0, y1);
        cnt++;
        double k, b;
        if (x0 == x1) {
            k = 0;
            b = max(y0, y1);
        } else {
            k = 1. * (y1 - y0) / (1. * (x1 - x0));
            b = 1. * y0 - 1. * x0 * k;
        }
        l[cnt] = {k, b};
        upd(x0, x1);
    }

    void insert(int p, int l, int r, int u) {
        int &v = s[p];
        int m = l + r >> 1;
        if (cmp(f(u, m), f(v, m)) == 1 or (cmp(f(u, m), f(v, m)) == 0 and u < v)) {
            swap(u, v);
        }
        if (cmp(f(u, l), f(v, l)) == 1 or (cmp(f(u, l), f(v, l)) == 0 and u < v)) {
            insert(lst, l, m, u);
        } else if (cmp(f(u, r), f(v, r)) == 1 or (cmp(f(u, r), f(v, r)) == 0 and u < v)) {
            insert(rst, m + 1, r, u);
        }
        return;
    }

    void upd(int p, int l, int r, int x, int y, int u) {
        if (x <= l and r <= y) {
            insert(p, l, r, u);
            return;
        }
        int m = l + r >> 1;
        if (x <= m)
            upd(lst, l, m, x, y, u);
        if (m < y)
            upd(rst, m + 1, r, x, y, u);
        return;
    }

    void upd(int x, int y) {
        upd(1, 1, n, x, y, cnt);
    }

    pair<double, int> pmax(const pair<double, int> &A, const pair<double, int> &B) {
        int tmp = cmp(A.first, B.first);
        if (tmp == 1)
            return A;
        else if (tmp == -1)
            return B;
        else
            return A.second < B.second ? A : B;
    }

    pair<double, int> query(int p, int l, int r, int now) {
        if (r < now or now < l)
            return {0, 0};
        int m = l + r >> 1;
        double res = f(s[p], now);
        if (l == r)
            return {res, s[p]};
        return pmax({res, s[p]}, pmax(query(lst, l, m, now), query(rst, m + 1, r, now)));
    }
};

const int P = 39989;
const int Q = 1e9;
int lastans;

inline int dep(int x) {
    return ((x + lastans - 1) % P) + 1;
}

inline int deq(int x) {
    return ((x + lastans - 1) % Q) + 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    LiChaoTree<Line> lct(P, n);

    vector<int> res;

    while(n--) {
        bool opt;
        cin >> opt;
        if (opt) {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            x0 = dep(x0);
            x1 = dep(x1);
            y0 = deq(y0);
            y1 = deq(y1);
            lct.addLine(x0, y0, x1, y1);
        } else {
            int k;
            cin >> k;
            k = dep(k);
            lastans = lct.query(1, 1, P, k).second;
            res.push_back(lastans);
        }
    }


    for (auto &i : res)
        cout << i << "\n";

    return 0;
}