// luogu P5731 230216
// https://www.luogu.com.cn/problem/P5731
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[9][9];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // code
    int n, i, j, k;
    cin >> n;
    i = 1, j = 1, k = 1;
    enum direction
    {
        you,
        xia,
        zuo,
        shang
    };
    direction dir;
    dir = you;
    while (k < n * n)
    {
        switch (dir)
        {
        case you:
        {
            if (j < n && !a[i][j + 1])

                a[i][j] = k, j++;
            else
            {
                dir = xia;
                k--;
            }
            break;
        }
        case xia:
        {
            if (i < n && !a[i + 1][j])

                a[i][j] = k, i++;
            else
            {
                dir = zuo;
                k--;
            }
            break;
        }
        case zuo:
        {
            if (j > 1 && !a[i][j - 1])

                a[i][j] = k, j--;
            else
            {
                dir = shang;
                k--;
            }
            break;
        }
        case shang:
        {
            if (i > 1 && !a[i - 1][j])

                a[i][j] = k,
                i--;
            else
            {
                dir = you;
                k--;
            }
            break;
        }
        default:
            break;
        }
        k++;
    }
    a[i][j] = k;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }

    //
    return 0;
}
