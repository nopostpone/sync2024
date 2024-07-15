#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 2e5 + 100;

int a[N];

int n, m;

struct node
{
    int l, r, ls[2], sum[2], rs[2];
} s[N * 4];

void pushup(int pos)
{
    for (int i : {0, 1})
    {
        s[pos].ls[i] = s[lst].ls[i];
        s[pos].rs[i] = s[rst].rs[i];
        if (s[lst].ls[i] == s[lst].r - s[lst].l + 1)
        {
            s[pos].ls[i] += s[rst].ls[i];
        }
        if (s[rst].rs[i] == s[rst].r - s[rst].l + 1)
        {
            s[pos].rs[i] += s[lst].rs[i];
        }
        s[pos].sum[i] = max({s[pos].ls[i],
                             s[pos].rs[i],
                             s[lst].sum[i],
                             s[rst].sum[i],
                             s[lst].rs[i] + s[rst].ls[i]});
    }
}

void build(int l, int r, int pos)
{
    s[pos] = {l, r, {0, 0}, {0, 0}, {0, 0}};
    if (l == r)
    {
        int i = a[l];
        s[pos].ls[i] = s[pos].rs[i] = s[pos].sum[i] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
}

void upd(int x, int pos = 1)
{
    if (s[pos].l == s[pos].r)
    {
        for (int i : {0, 1})
        {
            s[pos].rs[i] ^= 1;
            s[pos].ls[i] ^= 1;
            s[pos].sum[i] ^= 1;
        }
        return;
    }
    int m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        upd(x, lst);
    else
        upd(x, rst);
    pushup(pos);
    return;
}

int query(int x, int y, int i, int pos = 1)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        return s[pos].sum[i];
    }
    int m = s[pos].l + s[pos].r >> 1;
    int ans = 0;
    if (x <= m)
        ans += query(x, y, i, lst);
    if (m < y)
        ans += query(x, y, i, rst);
    return ans;
}

vector<int> res;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i += 2)
    {
        a[i] = 1;
    }
    build(1, n, 1);
    int x;
    while (m--)
    {
        cin >> x;
        upd(x);
        res.push_back(max(query(1, n, 0), query(1, n, 1)));
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    for (auto &i : res)
    {
        cout << i << endl;
    }
    return 0;
}