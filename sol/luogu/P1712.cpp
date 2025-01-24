#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct Seg {
    int n;
    vector<int> info, tag;

    Seg() = delete;
    Seg(int n_) {
        n = n_;
        info.assign(n * 4, {});
        tag.assign(n * 4, {});
    }
    void add(int p, int v) {
        info[p] += v;
        tag[p] += v;
    }
    void pull(int p) {
        info[p] = max(info[p * 2], info[p * 2 + 1]);
    }
    void push(int p) {
        add(p * 2, tag[p]);
        add(p * 2 + 1, tag[p]);
        tag[p] = {};
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (x >= r or y <= l) {
            return;
        }
        if (l >= x and r <= y) {
            return add(p, v);
        }
        int m = (l + r) / 2;
        push(p);
        rangeAdd(p * 2, l, m, x, y, v);
        rangeAdd(p * 2 + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeAdd(int l, int r, int x) {
        rangeAdd(1, 0, n, l, r, x);
    }
    int all() {
        return info[1];
    }
};

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][2];
        a[i][1]--;
        a[i][0] = a[i][2] - a[i][1];
    }

    ranges::sort(a);

    vector<int> f;
    f.reserve(2 * n);
    for (auto [_, x, y] : a) {
        f.push_back(x);
        f.push_back(y);
    }
    ranges::sort(f);
    f.erase(unique(f.begin(), f.end()), f.end());

    for (auto &[_, x, y] : a) {
        x = lower_bound(f.begin(), f.end(), x) - f.begin();
        y = lower_bound(f.begin(), f.end(), y) - f.begin();
    }

    const int k = f.size();
    Seg seg(k);

    int ans = inf;
    for (int i = -1, j = -1; i < n;) {
        while (seg.all() < m and i < n - 1) {
            i++;
            seg.rangeAdd(a[i][1], a[i][2], 1);
        }
        if (seg.all() < m) {
            break;
        }
        while (seg.all() == m and j < i) {
            j++;
            seg.rangeAdd(a[j][1], a[j][2], -1);
        }
        assert(i >= 0 and j >= 0);
        ans = min(ans, a[i][0] - a[j][0]);
    }

    cout << (ans == inf ? -1 : ans) << "\n";

    return 0;
}