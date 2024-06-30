// luogu P1152 240209
// https://www.luogu.com.cn/problem/P1152
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
using ll = long long;

ll a[N], diff[N];
bool r[N] = {0};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, i;
    bool flag = true;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (i = 1; i <= n - 1; ++i)
    {
        diff[i] = a[i + 1] > a[i] ? a[i + 1] - a[i] : a[i] - a[i + 1];
    }
    for (i = 1; i <= n - 1; ++i)
    {
        if (diff[i] < n)
        {
            r[diff[i]] = true;
        }
    }
    for (i = 1; i <= n - 1; ++i)
    {
        if (!r[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Jolly" << '\n';
    else
        cout << "Not jolly" << '\n';
    return 0;
}
