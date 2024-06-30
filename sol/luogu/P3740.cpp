#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;

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

bool vis[N];

void solve()
{
    int n = read(), m = read();
    s.insert(node(1, n + 100));
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        assign(l, r, i);
    }
    int res = 0;
    auto itr = split(n + 1), itl = split(1);
    for (; itl != itr; itl++)
        if (!vis[itl->v] and itl->v >= 1 and itl->v <= m)
            res++, vis[itl->v] = 1;
    write(res);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}