// https://www.luogu.com.cn/problem/P1113
// 拓扑排序
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e4 + 100;
const int inf = 0x7fffffff;

vector<int> g[N];
struct node
{
    int len, id, in;
    bool operator<(const node &o)
    {
        return in < o.in;
    }
} a[N];
int n;
int f[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].id >> a[i].len;
        int to;
        cin >> to;
        while (to != 0)
        {
            a[to].in++;
            g[i].push_back(to);
            cin >> to;
        }
    }
    queue<int> qu;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].in == 0)
            qu.push(i),f[i] = a[i].len;
    }
    while (!qu.empty())
    {
        int now = qu.front();
        qu.pop();
        for (auto &to : g[now])
        {
            f[to] = max(f[to], f[now] + a[to].len);
            a[to].in--;
            if (a[to].in == 0)
                qu.push(to);
        }
    }
    cout << *max_element(f + 1, f + 1 + n);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
