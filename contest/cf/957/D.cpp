#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e5 + 10;

int g[N];
int n, m, k;
vector<int> res;

void solve()
{
    cin >> n >> m >> k;
    int wcnt = 0;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'W')
            g[i] = 0;
        else if (ch == 'L')
            g[i] = 1;
        else if (ch == 'C')
            g[i] = 2;
    }
    if (m > n)
    {
        res.push_back(1);
        return;
    }
    int now = 0;
    int last = 10;
    g[0] = 1, g[n + 1] = 1;
    while (1)
    {
        if (now == n + 1)
        {
            res.push_back(1);
            return;
        }
        if (g[now] == 0)
        {
            for (int i = now + 1;; i++)
            {
                wcnt++;
                if (wcnt > k)
                {
                    res.push_back(0);
                    return;
                }
                if (g[i] == 2)
                {
                    res.push_back(0);
                    return;
                }
                if (g[i] == 1)
                {
                    now = i;
                    break;
                }
            }
        }
        else if (g[now] == 1)
        {
            if (now + m >= n + 1)
            {
                res.push_back(1);
                return;
            }
            int fwater = 0;
            last = now;
            for (int i = now + m; i > now; i--)
            {
                if (g[i] == 1)
                {
                    now = i;
                    break;
                }
                if (g[i] == 0 and i > fwater)
                {
                    fwater = i;
                }
            }
            if (now == last and fwater == 0)
            {
                res.push_back(0);
                return;
            }
            else if (now == last and fwater)
            {
                now = fwater;
            }
        }
        else
        {
            res.push_back(0);
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    for (auto &i : res)
    {
        if (i)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}