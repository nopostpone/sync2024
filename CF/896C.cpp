// https://codeforces.com/problemset/problem/896/C
// 阿朵莉树
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 1e5 + 100;
const int inf = 0x3f3f3f3f;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read()
{
    int x = 0, f = 1;
    char ch = nc();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = nc();
    }
    return x * f;
}
void write(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

struct node
{
    int l, r;
    mutable ll v;
    node(int L, int R = -1, ll V = 0) : l(L), r(R), v(V) {}
    bool operator<(const node &rhs) const
    {
        return l < rhs.l;
    }
};

set<node> s;

ll ksm(ll a, ll x, ll mod)
{
    ll res = 1, ans = a % mod;
    while (x)
    {
        if (x & 1)
            res = res * ans % mod;
        ans = ans * ans % mod;
        x >>= 1;
    }
    return res;
}

set<node>::iterator split(int pos)
{
    auto it = s.lower_bound(node(pos));
    if (it != s.end() and it->l == pos)
        return it;
    --it;
    int l = it->l, r = it->r;
    ll v = it->v;
    s.erase(it);
    s.insert(node(l, pos - 1, v));
    return s.insert(node(pos, r, v)).first;
}

void assign(int l, int r, ll v)
{
    auto itr = split(r + 1), itl = split(l);
    s.erase(itl, itr);
    s.insert(node(l, r, v));
}

void add(int l, int r, ll v)
{
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; itl++)
        itl->v += v;
}

ll rank_(int l, int r, int k)
{
    vector<pair<ll, int>> vp;
    auto itr = split(r + 1), itl = split(l);
    vp.clear();
    for (; itl != itr; ++itl)
        vp.push_back(pair<ll, int>(itl->v, itl->r - itl->l + 1));
    sort(vp.begin(), vp.end());
    for (vector<pair<ll, int>>::iterator it = vp.begin(); it != vp.end(); ++it)
    {
        k -= it->second;
        if (k <= 0)
            return it->first;
    }
}

ll sum(int l, int r, int x, int y)
{
    auto itr = split(r + 1), itl = split(l);
    ll res = 0;
    for (; itl != itr; itl++)
        res = (res + ll(itl->r - itl->l + 1) * ksm(itl->v, ll(x), ll(y))) % y;
    return res;
}

int n, m;
ll seed, vm, a[N];
const int _m = 1e9 + 7;

ll sd()
{
    ll tmp = seed;
    seed = (seed * 7 + 13) % _m;
    return tmp;
}

void solve()
{
    n = read(), m = read(), seed = read(), vm = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = (sd() % vm) + 1;
        s.insert(node(i, i, a[i]));
    }
    s.insert(node(n + 1, n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        int opt = int(sd() % 4) + 1;
        int l = int(sd() % n) + 1;
        int r = int(sd() % n) + 1;
        if (l > r)
            swap(l, r);
        int x, y;
        if (opt == 3)
            x = int(sd() % (r - l + 1)) + 1;
        else
            x = int(sd() % vm) + 1;
        if (opt == 4)
            y = int(sd() % vm) + 1;
        if (opt == 1)
            add(l, r, ll(x));
        else if (opt == 2)
            assign(l, r, ll(x));
        else if (opt == 3)
            write(rank_(l, r, x)), enter;
        else
            write(sum(l, r, x, y)), enter;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}