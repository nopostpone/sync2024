#include <bits/stdc++.h>
using namespace std;
#define int long long
template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
}
const int MAX = 2e5 + 5;
char seq[MAX], d[MAX];
struct Modify
{
    char who;
    int pos;
} q[MAX];
int n, m;
signed main()
{
    queue<int> qu;
    read(n), read(m);
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
        if (seq[i] != '_')
            qu.push(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].who;
        read(q[i].pos);
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
            {
                if (seq[x] == 'W')
                    seq[x - 1] = 'B';
                else
                    seq[x - 1] = 'W';
            }
            else
            {
                seq[x - 1] = seq[x];
            }
            qu.push(x - 1);
        }
        if (x + 1 >= 1 && x + 1 <= n && seq[x + 1] == '_')
        {
            if (d[x + 1] == 'R')
            {
                if (seq[x] == 'W')
                    seq[x + 1] = 'B';
                else
                    seq[x + 1] = 'W';
            }
            else
            {
                seq[x + 1] = seq[x];
            }
            qu.push(x + 1);
        }
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (seq[i] == seq[i - 1])
            continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}