// https://www.luogu.com.cn/problem/P4418
// K - D树
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 2e5 + 3;

const int LG = 18;

int n, m;
int cnt;
int rt[LG], b[N];
struct node
{
    int d[2];
    int val;
    int mx[2], mn[2];
    int ls, rs;
    int sum;
} t[N], lt, ht;

void upd(int p)
{
    for (int i = 0; i < 2; i++)
    {
        t[p].mx[i] = t[p].mn[i] = t[p].d[i];
        if (t[p].ls)
        {
            t[p].mx[i] = max(t[p].mx[i], t[t[p].ls].mx[i]);
            t[p].mn[i] = min(t[p].mn[i], t[t[p].ls].mn[i]);
        }
        if (t[p].rs)
        {
            t[p].mx[i] = max(t[p].mx[i], t[t[p].rs].mx[i]);
            t[p].mn[i] = min(t[p].mn[i], t[t[p].rs].mn[i]);
        }
    }
    t[p].sum = t[t[p].ls].sum + t[t[p].rs].sum + t[p].val;
}

int build(int l, int r, int k = 0)
{
    int pmid = (l + r) >> 1;
    nth_element(b + l, b + pmid, b + r + 1, [k](int x, int y)
                { return t[x].d[k] < t[y].d[k]; });
    int mid = b[pmid];
    if (l < pmid)
        t[mid].ls = build(l, mid - 1, k ^ 1);
    if (pmid < r)
        t[mid].rs = build(mid + 1, r, k ^ 1);
    upd(mid);
    return mid;
}

void append(int &p)
{
    if (!p)
        return;
    b[++cnt] = p;
    append(t[p].ls);
    append(t[p].rs);
    p = 0;
}

int query(int p)
{
    if (!p)
        return 0;
    bool flag = 0;
    for (int i = 0; i < 2; i++)
    {
        flag |= (!(lt.d[i] <= t[p].d[i] and t[p].mx[i] <= ht.d[i]));
    }
    if (!flag)
        return t[p].sum;
    for (int k = 0; k < 2; k++)
    {
        if (t[p].mx[k] < lt.d[k] or ht.d[k] < t[p].mn[k])
            return 0;
    }
    int ans = 0;
    flag = 0;
    for (int k = 0; k < 2; k++)
    {
        flag |= (!(lt.d[k] <= t[p].d[k] and t[p].d[k] <= ht.d[k]));
    }
    if (!flag)
        ans += t[p].val;
    return ans += query(t[p].ls) + query(t[p].rs);
}

void solve()
{
    cin >> n;
    int lastans = 0;
    n = 0;
    while (1)
    {
        int opt;
        cin >> opt;
        if (opt == 3)
            break;
        else if (opt == 1)
        {
            int x, y, A;
            cin >> x >> y >> A;
            x ^= lastans;
            A ^= lastans;
            y ^= lastans;
            t[++n] = {{x, y}, A};
            b[cnt = 1] = n;
            for (int i = 0;; i++)
            {
                if (!rt[i])
                {
                    rt[i] = build(1, cnt);
                    break;
                }
                append(rt[i]);
            }
        }
        else
        {
            cin >> lt.d[0] >> lt.d[1] >> ht.d[0] >> ht.d[1];
            lt.d[0] ^= lastans;
            lt.d[1] ^= lastans;
            ht.d[0] ^= lastans;
            ht.d[1] ^= lastans;
            lastans = 0;
            for (int i = 0; i < LG; i++)
                lastans += query(rt[i]);
            cout << lastans << endl;
        }
    }
}

signed main()
{
    solve();
    return 0;
}