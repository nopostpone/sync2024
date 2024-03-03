#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10;
char a[N][N], r[N][N], f[N][N], f5[N][N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, i, j, d;
    cin >> n;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> r[i][j];

    d = 7;
    bool IsEqual = 1;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            f[i][j] = a[i][j];
    // 1
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            f[j][n + 1 - i] = a[i][j];
            // cout << f[i][j] << ' ';
        }
    IsEqual = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (f[i][j] != r[i][j])
                IsEqual = 0;
    if (IsEqual)
    {
        d = 1;
        goto FLAG;
    }
    // 2
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            f[i][j] = a[n + 1 - i][n + 1 - j];
            // cout << f[i][j] << ' ';
        }
    IsEqual = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (f[i][j] != r[i][j])
                IsEqual = 0;
    if (IsEqual)
    {
        d = 2;
        goto FLAG;
    }
    // 3
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            f[i][j] = a[j][n + 1 - i];
    IsEqual = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (f[i][j] != r[i][j])
                IsEqual = 0;
    if (IsEqual)
    {
        d = 3;
        goto FLAG;
    }
    // 4
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            f[i][j] = a[i][n - j + 1];
    IsEqual = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (f[i][j] != r[i][j])
                IsEqual = 0;
    if (IsEqual)
    {
        d = 4;
        goto FLAG;
    }
    // 5
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            f5[j][n + 1 - i] = f[i][j];
    IsEqual = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (f5[i][j] != r[i][j])
                IsEqual = 0;
    if (IsEqual)
    {
        d = 5;
        goto FLAG;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            f5[i][j] = f[j][n + 1 - i];
    IsEqual = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (f5[i][j] != r[i][j])
                IsEqual = 0;
    if (IsEqual)
    {
        d = 5;
        goto FLAG;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            f5[i][j] = f[n + 1 - i][n + 1 - j];
    IsEqual = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (f5[i][j] != r[i][j])
                IsEqual = 0;
    if (IsEqual)
    {
        d = 5;
        goto FLAG;
    }

    // 6
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] != r[i][j])
                IsEqual = 0;
    if (IsEqual)
    {
        d = 6;
        goto FLAG;
    }
FLAG:
    cout << d << '\n';
    return 0;
}