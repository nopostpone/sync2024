#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// struct Node {
//     int l, r;
//     int mx;
//     ll sum;
//     void apply(const Node &o) {

//     }
// };

// template<class Node>
// struct SegmentTree {
// #define lst pos << 1
// #define rst pos << 1 | 1
//     int n;
//     vector<Node> s;
//     SegmentTree(int n_) : n(n_), s(n << 2) {}

//     void pull(int pos) {
        
//     }

//     void build(vector<int> init_, int l, int r, int pos = 1) {
//         s[pos].l = l, s[pos].r = r;
//         s[pos].sum = s[pos].mx = 0;
//         if (l == r) {
//             s[pos].sum = s[pos].mx = init_[l];
//             return;
//         }
//         int mid = l + r >> 1;
//         build(init_, l, m, lst);
//         build(init_, m + 1, r, rst);
//         pull(pos);
//         return;
//     }

//     void build(int init_[], int l, int r, int pos = 1) {
//         s[pos].l = l, s[pos].r = r;
//         s[pos].sum = s[pos].mx = 0;
//         if (l == r) {
//             s[pos].sum = s[pos].mx = init_[l];
//             return;
//         }
//         int mid = l + r >> 1;
//         build(init_, l, m, lst);
//         build(init_, m + 1, r, rst);
//         pull(pos);
//         return;
//     }

//     void modify(int x, int y, int k, int pos = 1) {
//         if ()
//     }
// };

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