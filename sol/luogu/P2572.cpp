// https://www.luogu.com.cn/problem/P2572
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
        s[pos].rev ^= 1;
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
        if (~s[lst].tag)
            s[lst].tag ^= 1;
        else
            s[lst].rev ^= 1;
        if (~s[rst].tag)
            s[rst].tag ^= 1;
        else
            s[rst].rev ^= 1;
        s[pos].rev = 0;
    }
}

// void pushdown(int pos) {
//     if (~s[pos].tag) {
//         int i = s[pos].tag;
//         int j = i ^ 1;
//         s[pos].rev = s[lst].rev = s[rst].rev = 0;
//         s[lst].tag = s[rst].tag = i;
//         s[lst].ls[i] = s[lst].rs[i] = s[lst].ss[i] = s[lst].r - s[lst].l + 1;
//         s[rst].rs[i] = s[rst].ls[i] = s[rst].ss[i] = s[rst].r - s[rst].l + 1;
//         s[lst].ls[j] = s[lst].rs[j] = s[lst].ss[j] = 0;
//         s[rst].rs[j] = s[rst].ls[j] = s[rst].ss[j] = 0;
//         s[lst].sum = i == 1 ? s[lst].r - s[lst].l + 1 : 0;
//         s[rst].sum = i == 1 ? s[rst].r - s[rst].l + 1 : 0;
//         s[pos].tag = -1;
//     }
//     if (s[pos].rev) {
//         if (~s[lst].tag)
//             s[lst].tag ^= 1;
//         else
//             s[lst].rev ^= 1;
//         if (~s[rst].tag)
//             s[rst].tag ^= 1;
//         else
//             s[rst].rev ^= 1;
//         s[lst].sum = s[lst].r - s[lst].l + 1 - s[lst].sum;
//         s[rst].sum = s[rst].r - s[rst].l + 1 - s[rst].sum;
//         // 喜欢不检查？
//         // 喜欢不检查？
//         // 喜欢不检查？
//         // 喜欢不检查？
//         swap(s[lst].ls[0], s[lst].ls[1]);
//         swap(s[rst].ls[0], s[rst].ls[1]);
//         swap(s[lst].rs[0], s[lst].rs[1]);
//         swap(s[rst].rs[0], s[rst].rs[1]);
//         swap(s[lst].ss[0], s[lst].ss[1]);
//         swap(s[rst].ss[0], s[rst].ss[1]);

//         s[pos].rev = 0;
//     }
//     return;
// }

void upd(int x, int y, int opt, int pos = 1) {
    pushdown(pos);
    if (x <= s[pos].l and s[pos].r <= y) {
        // if (opt == 0 or opt == 1) {
        //     s[pos].tag = opt;
        //     s[pos].rev = 0;
        //     s[pos].sum = (s[pos].r - s[pos].l + 1) * opt;
        //     s[pos].ls[opt] = s[pos].rs[opt] = s[pos].ss[opt] = s[pos].r - s[pos].l + 1;
        //     s[pos].ls[opt ^ 1] = s[pos].rs[opt ^ 1] = s[pos].ss[opt ^ 1] = 0;
        // } else if (opt == 2) {
        //     s[pos].rev ^= 1;
        //     s[pos].sum = s[pos].r - s[pos].l + 1 - s[pos].sum;
        //     swap(s[pos].ls[0], s[pos].ls[1]);
        //     swap(s[pos].rs[0], s[pos].rs[1]);
        //     swap(s[pos].ss[0], s[pos].ss[1]);
        // }
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

// 也可以返回一个结构体然后调用ss[1]
// node querymx(int x, int y, int pos = 1) {
//     pushdown(pos);
//     if (s[pos].l == x and s[pos].r == y) {
//         return s[pos];
//     }
//     int mid = s[pos].l + s[pos].r >> 1;
//     if (x > mid) {
//         return querymx(x, y, rst);
//     } else if (y <= mid) {
//         return querymx(x, y, lst);
//     } else {
//         node ret = {};
//         node L = querymx(x, mid, lst);
//         node R = querymx(mid + 1, y, rst);
//         ret.sum = L.sum + R.sum;
//         for (int i : {0, 1}) {
//             ret.ls[i] = L.ls[i];
//             if (i == 1 and L.sum == L.r - L.l + 1) {
//                 ret.ls[i] += R.ls[i];
//             } else if (i == 0 and L.sum == 0) {
//                 ret.ls[i] += R.ls[i];
//             }

//             ret.rs[i] = R.rs[i];
//             if (i == 1 and R.sum == R.r - R.l + 1) {
//                 ret.rs[i] += L.rs[i];
//             } else if (i == 0 and R.sum == 0) {
//                 ret.rs[i] += L.rs[i];
//             }
//             ret.ss[i] = max({L.rs[i] + R.ls[i], L.ss[i], R.ss[i]});
//         }
//         return ret;
//     }
// }

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