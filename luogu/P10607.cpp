// https://www.luogu.com.cn/problem/P10607
// 不会做的贪心
// 思路来自： https://www.luogu.com.cn/article/yc3rjfhz
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 2e5 + 100;

struct node
{
    int x, y, k;
} p[N], q[N];

bool cmp1(const node &a, const node &b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

bool cmp2(const node &a, const node &b)
{
    return a.y == b.y ? a.k > b.k : a.y < b.y;
}

int n, m;
int a[N], qq[N], pp[N];
ll res;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> q[i].x >> q[i].y >> q[i].k;
    for (int i = 1; i <= m; i++)
        p[i] = q[i];

    sort(p + 1, p + 1 + m, cmp1), sort(q + 1, q + 1 + m, cmp2);
    pp[n] = a[n];
    for (int i = n - 1; i; i--)
        pp[i] = min(pp[i + 1], a[i]);
    qq[1] = a[1];
    for (int i = 2; i <= n; i++)
        qq[i] = min(qq[i - 1], a[i]);

    int r = m, l = 1, k = 0;
    while (r >= 1)
    {
        int nr = p[r].k - k, nl = q[l].k - k;
        int nk = min(nl, nr);
        res += ll(nk) * ll(pp[p[r].x]);
        res += ll(nk) * ll(qq[q[l].y]);
        k += nk;
        while (p[r].k <= k and r >= 1)
            r--;
        while (q[l].k <= k and l <= m)
            l++;
    }
    res -= qq[q[1].y];
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}