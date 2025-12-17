#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(std::vector<Info>(n_, v_));
    }
    template <class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    template <class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template <class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};
constexpr int inf = 2e9;
struct Info {
    int max = -inf;
};

Info operator+(const Info &a, const Info &b) {
    return {std::max(a.max, b.max)};
}

using L = SegmentTree<Info>;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> b;

    vector<array<int, 3>> que(n);
    for (auto &[o, x, y] : que) {
        string s;
        cin >> s;
        if (s[0] == 'a') {
            o = 0;
        } else if (s[0] == 'r') {
            o = 1;
        } else {
            o = 2;
        }
        cin >> x >> y;
        b.push_back(x);
    }

    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());

    const int m = b.size();
    L seg(m);
    vector<set<int>> S(m);

    for (auto [o, x, y] : que) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin();
        if (o == 2) {
            int i = seg.findFirst(x + 1, m, [y](auto p) {
                return p.max > y;
            });
            if (i == -1) {
                cout << i << "\n";
            } else {
                cout << b[i] << " " << *S[i].upper_bound(y) << "\n";
            }
        } else {
            if (o) {
                S[x].erase(y);
            } else {
                S[x].insert(y);
            }
            seg.modify(x, {S[x].empty() ? -inf : *S[x].rbegin()});
        }
    }

    return 0;
}