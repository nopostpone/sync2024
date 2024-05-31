// https://www.luogu.com.cn/problem/P6485
// 把浮点全变成整型做
#include <bits/stdc++.h>
using namespace std;

int num[6];
int l, r;
double p;

void solve()
{
    cin >> p;
    l = int(p), r = l + 1;
    double res = 0, cnt = 0;
    while (1)
    {
        if (res == cnt * p and res!=0 and cnt!=0)
            break;
        cnt++;
        double a = abs(res - cnt * p + l), b = abs(res - cnt * p + r);
        if (a <= b)
            num[l]++, res += l;
        else
            num[r]++, res += r;
    }
    for (int i = 1; i <= 5; i++)
        cout << num[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        solve();
    return 0;
}
