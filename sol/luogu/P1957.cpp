// https://www.luogu.com.cn/problem/P1957
// 比较搞的模拟题
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int wei(int x)
{
    if (x == 0)
        return 1;
    int sum = 0;
    if (x < 0)
        sum++, x = -x;
    while (x)
        sum++, x /= 10;
    return sum;
}

const int N = 10010;
struct zfc
{
    char opt;
    int x, y, z;
    void pt()
    {
        int res;
        if (opt == 'a')
        {
            res = x + y;
            cout << x << '+' << y << '=' << res << endl;
        }
        else if (opt == 'b')
        {
            res = x - y;
            cout << x << '-' << y << '=' << res << endl;
        }
        else
        {
            res = x * y;
            cout << x << '*' << y << '=' << res << endl;
        }
        cout << (wei(res) + wei(x) + wei(y) + 2) << endl;
    }
} a[N];

string str[N];

void solve()
{
    int n;
    cin >> n;
    getline(cin, str[0]);
    for (int i = 1; i <= n; i++)
        getline(cin, str[i]);
    for (int i = 1; i <= n; i++)
    {
        char tmp = str[i][0];
        if (tmp >= 'a' and tmp <= 'c')
            a[i].opt = tmp, str[i].erase(str[i].begin()), str[i].erase(str[i].begin());
        else
            a[i].opt = a[i - 1].opt;
        auto it = str[i].begin();
        for (; *it != ' '; it++)
            a[i].x = (a[i].x * 10) + ((*it) ^ 48);
        it++;
        for (; it != str[i].end(); it++)
            a[i].y = (a[i].y * 10) + ((*it) ^ 48);
    }
    for (int i = 1; i <= n; i++)
        a[i].pt();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}