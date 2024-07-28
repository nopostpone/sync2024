#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

template <class T>
inline double seq(const T &x) {
    return x * x;
}

struct Tag {
    double add = 0;

    void apply(const Tag &t) {
        add += t.add;
    }
};

struct Info {
    double sum = 0;
    double sqr = 0;
    int act = 0;

    void apply(const Tag &t) {
        sqr += 2 * t.add * sum + act * seq(t.add);
        sum += act * t.add;
    }
};

const Info operator+(const Info &a, const Info &b) {
    Info c;
    c.act = a.act + b.act;
    c.sum = a.sum + b.sum;
    c.sqr = a.sqr + b.sqr;
    return c;
}

template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() : n(0) {}

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template <class T>
    LazySegmentTree(const std::vector<T> &init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(std::vector<Info>(n_, v_));
    }

    template <class T>
    void init(const std::vector<T> &init_) {
        n = init_.size();
        info.assign(4 << (int)std::log2(n), Info());
        tag.assign(4 << (int)std::log2(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r == l) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 1, n);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y || r < x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 1, n, l, r);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l > y || r < x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }

    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 1, n, l, r, v);
    }
};

double D(const Info &x) {
    double a = x.sum / x.act;
    double b = x.sqr / x.act;
    return (b - seq(a));
}

void solve() {
    cout << fixed << setprecision(4);
    int n, m;
    cin >> n >> m;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<Info> info(n + 1);
    for (int i = 1; i <= n; i++) {
        info[i].act = 1;
        info[i].sum = a[i];
        info[i].sqr = seq(a[i]);
    }

    LazySegmentTree<Info, Tag> l(info);

    vector<double> res;

    while (m--) {
        int opt;
        double x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            double k;
            cin >> k;
            l.rangeApply(x, y, {k});
        } else if (opt == 2) {
            res.push_back(l.rangeQuery(x, y).sum / double(y - x + 1));
        } else {
            res.push_back(D(l.rangeQuery(x, y)));
        }
    }

    for (auto &i : res) {
        cout << i << endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}