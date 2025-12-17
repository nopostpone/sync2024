// https://www.luogu.com.cn/problem/P2550
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;
bool b[33], a[N][33];
int p[N], result[7];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // code
    int n, i, j, x;
    cin >> n;
    for (i = 1; i <= 7; i++)
    {
        cin >> x;
        b[x] = 1;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 7; j++)
        {
            cin >> x;
            a[i][x] = 1;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 33; j++)
        {
            p[i] += a[i][j] && b[j];
        }
        if (p[i] != 0)
            result[p[i]]++;
    }
    for (i = 7; i >= 1; i--)
        cout << result[i] << ' ';
    //
    return 0;
}