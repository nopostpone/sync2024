// https://www.luogu.com.cn/problem/P6485
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e6 + 100;

int num[6];
long double p, res;
int l, r;

double tempres(int x)
{
    num[x]++;
    // for (int i = 1; i <= 5; i++)
    //     cout << num[i] << " \n"[i == 5];
    long double tmpres = 0;
    double time = 0;
    for (int i = 1; i <= 5; i++)
        tmpres += (num[i] * i), time += num[i];
    tmpres /= time;
    // cout << tmpres << ' ' << time << endl;
    num[x]--;
    return tmpres;
}

void __()
{
    double tl = tempres(l), tr = tempres(r);
    if (tr - p >= p - tl)
        num[l]++, res = tl;
    else
        num[r]++, res = tr;
    if (res == p)
    {
        for (int i = 1; i <= 5; i++)
            cout << num[i] << ' ';
        exit(0);
    }
    // cout << res << endl;
    __();
}

void solve()
{
    cin >> p;
    for (int i = 1; i <= 5; i++)
        if (p == i)
        {
            num[i]++;
            for (int j = 1; j <= 5; j++)
                cout << num[j] << ' ';
            return;
        }
        else if (p < 1 or p > 5)
        {
            for (int j = 1; j <= 5; j++)
                cout << num[j] << ' ';
            return;
        }
    l = int(p), r = l + 1;
    // cout << l << ' ' << r << endl;
    __();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
