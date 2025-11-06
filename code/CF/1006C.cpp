#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e5 + 3;

int lpos, rpos;
int n;
int a[N];
ll A, B;
ll qian[N], hou[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        qian[i] = a[i] + qian[i - 1];
    }
    for (int i = n; i; i--)
    {
        hou[i] = a[i] + hou[i + 1];
    }
    lpos = 0, rpos = n;
    ll sum = 0;
    while (lpos < rpos)
    {
        if (qian[lpos] == hou[rpos])
        {
            sum = max(sum, qian[lpos]);
            lpos++;
        }
        else if (qian[lpos] > hou[rpos])
        {
            rpos--;
        }
        else
        {
            lpos++;
        }
    }
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}