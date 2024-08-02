// https://www.luogu.com.cn/problem/P1439
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int n;
int a[N], b[N], pos[N], d[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        pos[a[i]] = i;
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        int now = pos[b[i]];
        if (now > d[len])
            d[++len] = now;
        else
            d[lower_bound(d + 1, d + 1 + len, now) - d] = now;
    }
    cout << len;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}