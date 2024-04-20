// https://www.luogu.com.cn/problem/P1494
// 莫队算法模板题
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e5 + 100;

int n, m, maxn;
int a[N], cnt[N];
ll ans1[N], ans2[N], sum;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

struct Q
{
    int l, r, idx;
    bool operator<(const Q &rhs) const
    {
        return (l / maxn == rhs.l / maxn) ? ((l / maxn) & 1 ? r < rhs.r : r > rhs.r) : l < rhs.l;
        // if (l / maxn != rhs.l / maxn)
        //     return l < rhs.l;
        // return (l / maxn) & 1 ? r < rhs.r : r > rhs.r;
    }
} q[N];

void add(int x)
{
    sum += cnt[x];
    cnt[x]++;
}

void del(int x)
{
    cnt[x]--;
    sum -= cnt[x];
}

void solve()
{
    n = read(), m = read();
    maxn = sqrt(n);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 0; i < m; i++)
        q[i].l = read(), q[i].r = read(), q[i].idx = i;
    sort(q, q + m);
    int l = 1, r = 0;
    for (int i = 0; i < m; i++)
    {
        if (q[i].l == q[i].r)
        {
            ans1[q[i].idx] = 0, ans2[q[i].idx] = 1;
            continue;
        }
        while (l > q[i].l)
            add(a[--l]);
        while (r < q[i].r)
            add(a[++r]);
        while (l < q[i].l)
            del(a[l++]);
        while (r > q[i].r)
            del(a[r--]);
        ans1[q[i].idx] = sum;
        ans2[q[i].idx] = (long long)(r - l + 1) * (r - l) / 2;
    }
    for (int i = 0; i < m; i++)
    {
        if (ans1[i] != 0)
        {
            long long g = gcd(ans1[i], ans2[i]);
            ans1[i] /= g, ans2[i] /= g;
        }
        else
            ans2[i] = 1;
        cout << ans1[i] << '/' << ans2[i] << endl;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}