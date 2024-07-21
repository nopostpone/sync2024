#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct SegmentTree {
#define lst p << 1
#define rst p << 1 | 1
    int n;
    vector<int> tag, sum;
    SegmentTree(int n_) : n(n_), tag(n << 2, 1), sum(n << 2, 1) {}

    void pull(int p) {
        sum[p] = (sum[lst] + sum[rst]) % P;
    }

    void mul(int p, int v) {
        tag[p] = 1LL * tag[p] * v % P;
        sum[p] = 1LL * sum[p] * v % P;
    }

    void push(int p) {
        mul(lst, tag[p]);
        mul(rst, tag[p]);
        tag[p] = 1;
    }

    ll query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return 0;
        }
        if (l >= x && r <= y) {
            return sum[p];
        }
        int m = l + r >> 1;
        push(p);
        ll ans = 0;
        ans += query(lst, l, m, x, y) % P;
        ans += query(rst, m + 1, r, x, y) % P;
        return ans;
    }

    void rangeMul(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {

            return;
        }
        if (l >= x && r <= y) {
            mul(p, v);
            return;
        }
    }
}

// int a[N];

// struct node
// {
//     ll l, r, sum, add;
// } s[N * 4];

// void pushdown(ll pos)
// {
//     s[lst].sum += s[pos].add * (s[lst].r - s[lst].l + 1);
//     s[rst].sum += s[pos].add * (s[rst].r - s[rst].l + 1);
//     s[lst].add += s[pos].add;
//     s[rst].add += s[pos].add;
//     s[pos].add = 0;
// }

// void pushup(ll pos)
// {
//     s[pos].sum += s[lst].sum + s[rst].sum;
// }

// void build(ll l, ll r, ll pos)
// {
//     s[pos].l = l, s[pos].r = r, s[pos].sum = s[pos].add = 0;
//     if (l == r)
//     {
//         s[pos].sum = a[l];
//         return;
//     }
//     ll m = (l + r) >> 1;
//     build(l, m, lst);
//     build(m + 1, r, rst);
//     pushup(pos);
// }

// void upd(ll x, ll y, ll pos, ll k)
// {
//     if (x > y)
//         swap(x, y);
//     if (x <= s[pos].l and s[pos].r <= y)
//     {
//         s[pos].sum += (s[pos].r - s[pos].l + 1) * k;
//         s[pos].add += k;
//         return;
//     }
//     pushdown(pos);
//     ll m = s[pos].l + s[pos].r >> 1;
//     if (x <= m)
//         upd(x, y, lst, k);
//     if (m < y)
//         upd(x, y, rst, k);
//     pushup(pos);
//     return;
// }

// ll query(ll x, ll y, ll pos)
// {
//     if (x > y)
//         swap(x, y);
//     if (x <= s[pos].l and s[pos].r <= y)
//     {
//         return s[pos].sum;
//     }
//     pushdown(pos);
//     ll m = s[pos].l + s[pos].r >> 1;
//     ll ans = 0;
//     if (x <= m)
//         ans += query(x, y, lst);
//     if (m < y)
//         ans += query(x, y, rst);
//     return ans;
// }