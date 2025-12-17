// https://www.luogu.com.cn/problem/P2572
// 区间赋值，区间翻转
// 询问区间最大连续子段和区间和
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int n, m;
int a[N];
vector<int> res;

#define lst pos << 1
#define rst pos << 1 | 1

void ext() {
    cerr << "??" << endl;
    exit(0);
}

struct node {
    int l, r;
    int ss[2], ls[2], rs[2], sum;
    int tag, rev;
} s[N << 2];

void pullup(int pos) {
    s[pos].sum = s[lst].sum + s[rst].sum;
    for (int i : {0, 1}) {
        s[pos].ls[i] = s[lst].ls[i];
        s[pos].rs[i] = s[rst].rs[i];
        if (s[lst].ls[i] == s[lst].r - s[lst].l + 1) {
            s[pos].ls[i] += s[rst].ls[i];
        }
        if (s[rst].rs[i] == s[rst].r - s[rst].l + 1) {
            s[pos].rs[i] += s[lst].rs[i];
        }
        s[pos].ss[i] = max({s[pos].ls[i], s[pos].rs[i], s[lst].ss[i], s[rst].ss[i], s[lst].rs[i] + s[rst].ls[i]});
    }
    return;
}

void build(int l, int r, int pos = 1) {
    s[pos] = {};
    s[pos].l = l, s[pos].r = r;
    s[pos].tag = -1;
    if (l == r) {
        int i = a[l];
        s[pos].ss[i] = s[pos].ls[i] = s[pos].rs[i] = 1;
        s[pos].sum = i;
        return;
    }
    int m = l + r >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pullup(pos);
    return;
}

void modify(int pos, int o) {
    if (o == 0 or o == 1) {
        s[pos].tag = o;
        s[pos].rev = 0;
        s[pos].sum = (s[pos].r - s[pos].l + 1) * o;
        s[pos].ls[o] = s[pos].rs[o] = s[pos].ss[o] = s[pos].r - s[pos].l + 1;
        s[pos].ls[o ^ 1] = s[pos].rs[o ^ 1] = s[pos].ss[o ^ 1] = 0;
    } else {
        if (~s[pos].tag) {
            s[pos].tag ^= 1;
        } else {
            s[pos].rev ^= 1;
        }
        s[pos].sum = s[pos].r - s[pos].l + 1 - s[pos].sum;
        swap(s[pos].ls[0], s[pos].ls[1]);
        swap(s[pos].rs[0], s[pos].rs[1]);
        swap(s[pos].ss[0], s[pos].ss[1]);
    }
}

void pushdown(int pos) {
    if (~s[pos].tag) {
        modify(lst, s[pos].tag);
        modify(rst, s[pos].tag);
        s[pos].rev = 0;
        s[pos].tag = -1;
    }
    if (s[pos].rev) {
        modify(lst, 2);
        modify(rst, 2);
        s[pos].rev = 0;
    }
}

void upd(int x, int y, int opt, int pos = 1) {
    pushdown(pos);
    if (x <= s[pos].l and s[pos].r <= y) {
        modify(pos, opt);
        return;
    }
    int mid = s[pos].l + s[pos].r >> 1;
    if (x <= mid)
        upd(x, y, opt, lst);
    if (mid < y)
        upd(x, y, opt, rst);
    pullup(pos);
    return;
}

int querysum(int x, int y, int pos = 1) {
    if (x <= s[pos].l and s[pos].r <= y) {
        return s[pos].sum;
    }
    pushdown(pos);
    int mid = s[pos].l + s[pos].r >> 1;
    int tmp = 0;
    if (x <= mid)
        tmp += querysum(x, y, lst);
    if (mid < y)
        tmp += querysum(x, y, rst);
    return tmp;
}

int querymx(int x, int y, int pos = 1) {
    if (x <= s[pos].l and s[pos].r <= y) {
        return s[pos].ss[1];
    }
    pushdown(pos);
    int mid = s[pos].l + s[pos].r >> 1;
    int tmp = 0;
    if (x <= mid)
        tmp = max(tmp, querymx(x, y, lst));
    if (mid < y)
        tmp = max(tmp, querymx(x, y, rst));

    int tmpr = min(s[lst].rs[1], mid - x + 1), tmpl = min(s[rst].ls[1], y - mid);
    tmp = max(tmp, tmpr + tmpl);
    return tmp;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n);
    for (int i = 1; i <= m; i++) {
        int opt, l, r;
        cin >> opt >> l >> r;
        l++, r++;
        if (opt >= 0 and opt <= 2) {
            upd(l, r, opt);
        } else if (opt == 3) {
            res.push_back(querysum(l, r));
        } else if (opt == 4) {
            res.push_back(querymx(l, r));
        }
    }
    for (auto i : res) {
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