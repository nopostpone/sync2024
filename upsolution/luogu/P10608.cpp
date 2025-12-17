#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

char seq[N], d[N];
struct Modify
{
    char who;
    int pos;
} q[N];

int n, m;
ll res = 1;

void solve()
{
    queue<int> qu;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
        if (seq[i] != '_')
            qu.push(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].who >> q[i].pos;
        d[q[i].pos] = q[i].who;
    }
    if (qu.empty())
    {
        seq[q[1].pos] = 'W';
        qu.push(q[1].pos);
    }
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        if (x - 1 >= 1 && x - 1 <= n && seq[x - 1] == '_')
        {
            if (d[x - 1] == 'R')
                seq[x - 1] = (seq[x] == 'W') ? 'B' : 'W';
            else
                seq[x - 1] = seq[x];
            qu.push(x - 1);
        }
        if (x + 1 >= 1 && x + 1 <= n && seq[x + 1] == '_')
        {
            if (d[x + 1] == 'R')
                seq[x + 1] = (seq[x] == 'W') ? 'B' : 'W';
            else
                seq[x + 1] = seq[x];
            qu.push(x + 1);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (seq[i] == seq[i - 1])
            continue;
        res++;
    }
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}