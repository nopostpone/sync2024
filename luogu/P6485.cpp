// https://www.luogu.com.cn/problem/P6485
// 把浮点全变成整型做
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e6 + 100;

int num[6];
int l, r;
double p;

void solve()
{
    cin >> p;
    l = int(p), r = l + 1;
    double res = 0, sum = 0;
    while (1)
    {
        if (res == sum * p and res!=0 and sum!=0)
            break;
        sum++;
        double a = abs(res - sum * p + l), b = abs(res - sum * p + r);
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
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
