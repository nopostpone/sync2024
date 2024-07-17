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

struct node {
    int l, r;
    int sum[2], ls[2], rs[2];
    int tg01, rev;
} s[N << 2];

void pushup(int pos) {
    for (int i : {0, 1}) {
        s[pos].ls[i] = s[lst].ls[i];
        s[pos].rs[i] = s[rst].rs[i];
        if (s[lst].ls[i] == s[lst].r - s[lst].l + 1) {
            s[pos].ls[i] += s[rst].ls[i];
        }
        if (s[rst].rs[i] == s[rst].r - s[rst].l + 1) {
            s[pos].rs[i] += s[lst].rs[i];
        }
        s[pos].sum[i] = max({s[lst].sum[i],
                             s[rst].sum[i],
                             s[pos].ls[i],
                             s[pos].rs[i],
                             s[lst].rs[i] + s[rst].ls[i]});
    }
}

void build(int l, int r, int pos = 1) {
    s[pos] = {l, r, {0, 0}, {0, 0}, {0, 0}, -1, 0};
    if (l == r) {
        int i = a[l];
        s[pos].sum[i] = s[pos].ls[i] = s[pos].rs[i] = 1;
        return;
    }
    int m = l + r >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
    return;
}

void modify(int pos, int opt) {
    if (opt == 2) {
        for (int i: {0, 1}) {
            s[pos].rev ^= 1;
            swap(s[pos].ls[0], s[pos].ls[1]);
            swap(s[pos].rs[0], s[pos].rs[1]);
            swap(s[pos].sum[0], s[pos].sum[1]);
            if (~s[pos].tg01) 
                s[pos].tg01 ^= 1;
        }
    } else {
        s[pos].tg01 = opt;
        s[pos].rev = 0;
        s[pos].sum[opt] = s[pos].ls[opt] = s[pos].rs[opt] = s[pos].r - s[pos].l + 1;
    }
}

void pushdown(int pos) {
    if (~tg01) {

    }
}

void upd(int x, int y, int k, int pos = 1) {
    if (y < s[pos].l or s[pos].r < x)
        return;
    if (x <= s[pos].l and s[pos].r <= y) {

        return;
    }
    pushdown(pos);
    int mid = s[pos].l + s[pos].r >> 1;
    if (x <= mid)
        upd(x, y, k, lst);
    if (mid < y)
        upd(x, y, k, rst);
    pushup(pos);
    return;
}

int query(int x, int y, int pos = 1) {
}

void solve() {
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 0) {

        } else if (opt == 1) {

        } else if (opt == 2) {

        } else if (opt == 3) {

        } else if (opt == 4) {

        } else {
            cerr << opt << endl;
            exit(0);
        }
    }
    for (auto i : res) {
        cout << i << endl;
    }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}