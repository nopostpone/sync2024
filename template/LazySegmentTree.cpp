struct Tag {
    ll add = 0;
 
    void apply(const Tag& t) {
        add += t.add;
    }
};

struct Info {
    ll min = inf;
    ll max = -inf;
    ll sum = 0;
    ll act = 0;
 
    void apply(const Tag& t) {
        min += t.add;
        max += t.add;
        sum += act * t.add;
    }
};
 
Info operator+(const Info& a, const Info& b) {
    Info c;
    c.min = std::min(a.min, b.min);
    c.max = std::max(a.max, b.max);
    c.sum = a.sum + b.sum;
    c.act = a.act + b.act;
    return c;
}
 
template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
 
    LazySegmentTree() : n(0) {}
 
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
 
    template<class T>
    LazySegmentTree(const std::vector<T>& init_) {
        init(init_);
    }
 
    void init(int n_, Info v_ = Info()) {
        init(std::vector<Info>(n_, v_));
    }
 
    template<class T>
    void init(const std::vector<T>& init_) {
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
 
    void apply(int p, const Tag& v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
 
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
 
    void modify(int p, int l, int r, int x, const Info& v) {
        if (r == l) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        }
        else {
            modify(2 * p + 1, m + 1, r, x, v);
        }
        pull(p);
    }
 
    void modify(int p, const Info& v) {
        modify(1, 1, n, p, v);
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
 
    void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
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
 
    void rangeApply(int l, int r, const Tag& v) {
        return rangeApply(1, 1, n, l, r, v);
    }
};