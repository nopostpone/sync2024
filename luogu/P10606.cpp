// https://www.luogu.com.cn/problem/P10606
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
struct node
{
    int x, y;
    bool operator<(const node &o) const
    {
        return x > o.x;
    }
} q[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> q[i].x >> q[i].y;
    sort(q + 1, q + 1 + m);
    int mn = 0x3f3f3f3f;
    for (int i = q[1].x; i <= n; i++)
        mn = min(mn, a[i]);
    cout << mn;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}