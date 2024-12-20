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
};
struct Node {
    int cnt{};
};
Node operator+(const Node &a, const Node &b) {
    return {max(a.cnt, b.cnt)};
}

template <class T>
struct RMQidx {
    const int n;
    const int logn;
    
    std::vector<T> a;
    std::vector<std::vector<int>> jump;

    constexpr RMQidx(const std::vector<T> &init)
        : n{(int)init.size()}, logn{std::__lg(n)}, jump(logn + 1), a(init) {

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        auto comp = [&](auto x, auto y) {
            if (a[x] == a[y]) {
                return x < y;
            } else {
                return a[x] < a[y];
            }
        };
        
        jump[0] = id;

        for (int j = 1; j <= logn; j++) {
            jump[j].resize(n - (1 << j) + 1);
        }

        for (int j = 0; j < logn; j++) {
            const int limit = n - (1 << (j + 1));
            for (int i = 0; i <= limit; i++) {
                jump[j + 1][i] = std::min(jump[j][i], jump[j][i + (1 << j)], comp);
            }
        }
    }

    constexpr int operator()(int l, int r) const {
        int log = std::__lg(r - l);
        return std::min(jump[log][l], jump[log][r - (1 << log)], [&](auto x, auto y) {
            return this->a[x] < this->a[y];
        });
    }
};

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] - i + n - 1;
    }

    vector<Node> init(2 * n);
    for (int i = 0; i < k - 1; i++) {
        init[a[i]].cnt++;
    }
    SegmentTree<Node> seg(init);

    // b : 预处理 [i, i + k) 的答案
    vector<ll> b(n - k + 1);
    for (int i = k - 1; i < n; i++) {
        auto v = seg.rangeQuery(a[i], a[i] + 1);
        v.cnt++;
        seg.modify(a[i], v);

        int p = i - k + 1;
        b[p] = k - seg.rangeQuery(0, 2 * n).cnt;
        
        auto w = seg.rangeQuery(a[p], a[p] + 1);
        if (w.cnt > 0) {
            w.cnt--;
        }
        seg.modify(a[p], w);
    }

    // 单调栈处理出每个位置右边的，第一个小于它的位置
    stack<int> stk;

    vector<int> suf(n - k + 1);
    for (int i = n - k; ~i; i--) {
        while (not stk.empty() and b[stk.top()] >= b[i]) {
            stk.pop();
        }
        if (stk.empty()) {
            suf[i] = n - k + 1;
        } else {
            suf[i] = stk.top();
        }
        stk.push(i);
    }

    // 假设 dp[l] 表示以 l 开始的，对答案的贡献，这么设置状态，方便做差分
    vector<ll> dp(n - k + 1);
    for (int i = n - k; ~i; i--) {
        dp[i] = b[i] * (suf[i] - i) + (suf[i] == n - k + 1 ? 0 : dp[suf[i]]);
    }

    RMQidx<ll> rmq(b);
    
    // 每个提问 [x, y)，先找到其中最小的元素位置 z，这个最小的元素管辖从它开始到 y 结束，贡献易得
    // 然后再求 [x, z)，就是 dp[x] - dp[z]
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y -= k;

        int z = rmq(x, y + 1);

        cout << b[z] * (y - z + 1) + dp[x] - dp[z] << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}