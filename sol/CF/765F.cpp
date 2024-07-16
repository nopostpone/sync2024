// https://codeforces.com/problemset/problem/765/F
// 考虑离线保存 (l, r)，每个线段树中额外用一个数组存管辖区间内所有数字并排序，查找时二分查找
// 维护后缀最小值，从右往左更新，每个点被修改的次数不超过 loga 次
// 复杂度 O ( nlognloga )
#include <bits/stdc++.h>
#define lst pos << 1
#define rst pos << 1 | 1
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 3e5 + 3;

vector<ll> a;
int n, m, lim;

struct node {
    int l, r;
    int mnv;
    // 存管辖区间所有数，二分查找
    vector<int> lis;
} s[N << 2];

inline void pushup(int pos) {
    s[pos].mnv = min(s[lst].mnv, s[rst].mnv);
}

void build(int l, int r, int pos = 1) {
    s[pos].l = l, s[pos].r = r, s[pos].mnv = 0x3f3f3f3f;
    for (int i = l; i <= r; i++) {
        s[pos].lis.push_back(a[i]);
    }
    sort(s[pos].lis.begin(), s[pos].lis.end());
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
    return;
}

void upd(int x, int R, int pos = 1) {
    if (1 <= s[pos].l and s[pos].r <= R) {
        auto it = lower_bound(s[pos].lis.begin(), s[pos].lis.end(), x);
        if (it != s[pos].lis.end()) {
            s[pos].mnv = min(s[pos].mnv, *it - x);
        }
        if (it != s[pos].lis.begin()) {
            s[pos].mnv = min(s[pos].mnv, x - *(it - 1));
        }
        if (s[pos].mnv >= lim) {
            return;
        }
    }
    if (s[pos].l == s[pos].r) {
        lim = min(lim, s[pos].mnv);
        return;
    }
    int mid = s[pos].l + s[pos].r >> 1;
    if (R > mid) {
        upd(x, R, rst);
    }
    upd(x, R, lst);
    pushup(pos);
    lim = min(lim, s[pos].mnv);
}

int query(int L, int pos = 1) {
    if (L <= s[pos].l and s[pos].r <= n) {
        return s[pos].mnv;
    }
    int tmp = 0x3f3f3f3f;
    int mid = s[pos].l + s[pos].r >> 1;
    if (L <= mid) {
        tmp = min(tmp, query(L, lst));
    }
    tmp = min(tmp, query(L, rst));
    return tmp;
}

struct Q {
    int l, r, id;
    inline bool operator<(const Q &o) const {
        return r == o.r ? l < o.l : r < o.r;
    }
};

vector<Q> qq;
vector<int> res;

void solve() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    qq.resize(m + 1);
    res.resize(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> qq[i].l >> qq[i].r;
        qq[i].id = i;
    }
    // 离线，排序
    sort(qq.begin() + 1, qq.end());
    build(1, n);
    int loc = 1;
    // 找到一个右端点 > 1 的询问
    while (qq[loc].r <= 1) {
        loc++;
    }
    for (int i = 2; i <= n; i++) {
        lim = 0x3f3f3f3f;
        upd(a[i], i - 1);
        while (qq[loc].r == i) {
            res[qq[loc].id] = query(qq[loc].l);
            ++loc;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}