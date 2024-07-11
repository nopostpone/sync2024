int a[N];

struct segtree
{
    ll l, r, sum, add;
} s[N * 4];

void pushdown(ll pos)
{
    s[lst].sum += s[pos].add * (s[lst].r - s[lst].l + 1);
    s[rst].sum += s[pos].add * (s[rst].r - s[rst].l + 1);
    s[lst].add += s[pos].add;
    s[rst].add += s[pos].add;
    s[pos].add = 0;
}

void pushup(ll pos)
{
    s[pos].sum += s[lst].sum + s[rst].sum;
}

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r, s[pos].sum = s[pos].add = 0;
    if (l == r)
    {
        s[pos].sum = a[l];
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
}

void upd(ll x, ll y, ll pos, ll k)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        s[pos].sum += (s[pos].r - s[pos].l + 1) * k;
        s[pos].add += k;
        return;
    }
    pushdown(pos);
    ll m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        upd(x, y, lst, k);
    if (m < y)
        upd(x, y, rst, k);
    pushup(pos);
    return;
}

ll getsum(ll x, ll y, ll pos)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        return s[pos].sum;
    }
    pushdown(pos);
    ll m = s[pos].l + s[pos].r >> 1;
    ll ans = 0;
    if (x <= m)
        ans += getsum(x, y, lst);
    if (m < y)
        ans += getsum(x, y, rst);
    return ans;
}