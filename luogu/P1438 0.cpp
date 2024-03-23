#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N], p[N];
ll shu[N];
int n;

struct caozuo
{
    int l, r, k, d;
} cz[N];

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int k)
{
    for (int i = x; i <= n; i += lowbit(i))
        shu[i] += k;
}

ll ask(int p)
{
    ll ans = 0;
    for (int i = p; i > 0; i -= lowbit(i))
        ans += shu[i];
    return ans;
}

void solve()
{
    int m;
    cin >> n >> m;
    int i;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    int as, i1 = 1, i2 = 1;
    for (i = 1; i <= m; i++)
    {
        cin >> as;
        if (as == 1)
            // cout << i1;
            cin >> cz[i1].l >> cz[i1].r >> cz[i1].k >> cz[i1++].d;
        else if (as == 2)
            cin >> p[i2++];
    }
    i1--, i2--;
    for (i = 1; i <= n; i++)
        add(i, a[i] - a[i - 1]);
    // add(2, 1);
    // for (i = 1; i <= n; i++)
    //     cout << shu[i] << endl;
    for (i = 1; i <= i1; i++)
    {
        add(cz[i].l, cz[i].k);
        for (int j = cz[i].l + 1; j <= cz[i].r; j++)
        {
            add(j, cz[i].d);
        }
        add(cz[i].r + 1, -cz[i].k - cz[i].d * (cz[i].r - cz[i].l));
    }
    cout << ask(1);
    // for (i = 1; i <= i2; i++)
    //     cout << ask(p[i]) << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}