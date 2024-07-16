// https://www.luogu.com.cn/problem/P4145
// 区间开方 - 询问区间和
// 维护区间最大值，若最大值为 1，则开方无意义，若不是 1，继续遍历直到叶子节点。
#include <bits/stdc++.h>
#define lst pos << 1
#define rst pos << 1 | 1
#define endl '\n'
#define spc << ' ' <<
using namespace std;
using ll = long long;

const int N = 1e5;

vector<ll> a;
int n, m;

struct node {
    int l, r, sum, fr, mi, bk;
} s[N * 4];

void pushdown(int pos) {
}

void pushup(int pos) {
    s[pos].mx = max(s[lst].mx, s[rst].mx);
    s[pos].sum = s[lst].sum + s[rst].sum;
}

void build(int l, int r, int pos = 1) {
    s[pos] = {l, r, 0, 0};
    if (l == r) {
        s[pos].sum = s[pos].mx = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
    return;
}

void upd(int x, int y, int pos = 1) {
    if (s[pos].mx == 1) {
        return;
    }
    if (s[pos].l == s[pos].r) {
        s[pos].mx = s[pos].sum = sqrt(s[pos].sum);
        return;
    }
    int m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        upd(x, y, lst);
    if (m < y)
        upd(x, y, rst);
    pushup(pos);
    return;
}

void assign(int x, int y, int k, int pos = 1) {
    if (x <= s[pos].l and s[pos].r <= y) {
        
    }
}

ll query(int x, int y, int pos = 1) {
    if (x <= s[pos].l and s[pos].r <= y) {
        return s[pos].sum;
    }
    int m = s[pos].l + s[pos].r >> 1;
    ll ans = 0;
    if (x <= m)
        ans += query(x, y, lst);
    if (m < y)
        ans += query(x, y, rst);
    return ans;
}

vector<ll> res;

void solve() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n);

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        if (opt == 0) {
            upd(x, y);
        } else {
            res.push_back(query(x, y));
        }
    }
    for (auto i : res) {
        cout << i << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}