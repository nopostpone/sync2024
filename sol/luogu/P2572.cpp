// https://www.luogu.com.cn/problem/P2572
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int n, m;
vector<int> a;
vector<int> res;

#define lst pos << 1
#define rst pos << 1 | 1

void ext() {
    cerr << "??" << endl;
    exit(0);
}

struct node {
    int l, r;
    int ss[2], ls[2], rs[2], ans;
    int tg01, rev;
} s[N << 2];

void pushup(int pos) {
    s[pos].ans = s[lst].ans + s[rst].ans;
    for (int i : {0, 1}) {
        s[pos].ls[i] = s[lst].ls[i];
        s[pos].rs[i] = s[rst].rs[i];
        if (s[lst].ls[i] == s[lst].r - s[lst].l + 1) {
            s[pos].ls[i] += s[rst].ls[i];
        }
        if (s[rst].rs[i] == s[rst].r - s[rst].l + 1) {
            s[pos].rs[i] += s[lst].rs[i];
        }
        s[pos].ss[i] = max({s[lst].ss[i],
                            s[rst].ss[i],
                            s[pos].ls[i],
                            s[pos].rs[i],
                            s[lst].rs[i] + s[rst].ls[i]});
    }
}

void build(int l, int r, int pos = 1) {
    s[pos] = {l, r, {0, 0}, {0, 0}, {0, 0}, 0, -1, 0};
    if (l == r) {
        int i = a[l];
        s[pos].ss[i] = s[pos].ls[i] = s[pos].rs[i] = 1;
        s[pos].ans = i == 1 ? 1 : 0;
        return;
    }
    int m = l + r >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
    return;
}

void pushdown(int pos) {
    // 如果有赋01
    if (~s[pos].tg01) {
        s[pos].rev = s[lst].rev = s[rst].rev = 0;
        int i = s[pos].tg01;
        int j = i ^ 1;
        // 左右子树也赋01
        s[lst].tg01 = s[rst].tg01 = i;
        s[lst].ls[i] = s[lst].rs[i] = s[lst].ss[i] = s[lst].r - s[lst].l + 1;
        s[rst].rs[i] = s[rst].ls[i] = s[rst].ss[i] = s[rst].r - s[rst].l + 1;
        s[lst].ls[j] = s[lst].rs[j] = s[lst].ss[j] = 0;
        s[rst].rs[j] = s[rst].ls[j] = s[rst].ss[j] = 0;
        s[lst].ans = i == 1 ? s[lst].r - s[lst].l + 1 : 0;
        s[rst].ans = i == 1 ? s[rst].r - s[rst].l + 1 : 0;
        s[pos].tg01 = -1;
    }
    if (s[pos].rev) {
        // 左右子树也翻转
        s[lst].rev ^= 1;
        s[rst].rev ^= 1;
        s[lst].ans = s[lst].r - s[lst].l + 1 - s[lst].ans;
        s[rst].ans = s[rst].r - s[rst].l + 1 - s[rst].ans;
        swap(s[lst].ls[0], s[lst].ls[1]);
        swap(s[rst].ls[0], s[lst].ls[1]);
        swap(s[lst].rs[0], s[lst].rs[1]);
        swap(s[rst].rs[0], s[lst].rs[1]);
        swap(s[lst].ss[0], s[lst].ss[1]);
        swap(s[rst].ss[0], s[lst].ss[1]);
        s[pos].rev = 0;
    }
}

void upd(int x, int y, int opt, int pos = 1) {
    if (x <= s[pos].l and s[pos].r <= y) {
        if (opt == 0 or opt == 1) {
            s[pos].tg01 = opt;
            s[pos].rev = 0;
            s[pos].ans = (s[pos].r - s[pos].l + 1) * opt;
            s[pos].ls[opt] = s[pos].rs[opt] = s[pos].ss[opt] = s[pos].r - s[pos].l + 1;
            s[pos].ls[opt ^ 1] = s[pos].rs[opt ^ 1] = s[pos].ss[opt ^ 1] = 0;
        } else if (opt == 2) {
            s[pos].rev ^= 1;
            s[pos].ans = s[pos].r - s[pos].l + 1 - s[pos].ans;
            swap(s[pos].ls[0], s[pos].ls[1]);
            swap(s[pos].rs[0], s[pos].rs[1]);
            swap(s[pos].ss[0], s[pos].ss[1]);
        }
        return;
    }
    pushdown(pos);
    int mid = s[pos].l + s[pos].r >> 1;
    if (x <= mid)
        upd(x, y, opt, lst);
    if (mid < y)
        upd(x, y, opt, rst);
    pushup(pos);
    return;
}

int querysum(int x, int y, int pos = 1) {
    if (x <= s[pos].l and s[pos].r <= y) {
        return s[pos].ans;
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
    a.resize(n + 1);
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
        } else {
            ext();
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