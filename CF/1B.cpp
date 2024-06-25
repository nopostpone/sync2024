// https://codeforces.com/contest/1/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

string a[N];

string _10_27(int col)
{
    string res = "";
    int wi[10] = {0};
    int i = 1;
    while (col)
    {
        if (col % 26 == 0)
        {
            wi[i] = 26;
            col = col / 26 - 1;
        }
        else
        {
            wi[i] = col % 26;
            col /= 26;
        }
        i++;
    }
    i--;
    for (int j = i; j; j--)
        res.push_back(char(wi[j] + 64));
    return res;
}

int _27_10(string str)
{
    int res = 0;
    int len = str.length();
    int w[10] = {0};
    for (int i = 0; i < len; i++)
        w[i + 1] = int(str[i] - 'A' + 1);
    for (int i = len; i; i--)
        res += pow(26, len - i) * w[i];
    return res;
}

void s2(string &str)
{
    string tmp = str;
    bool flag = 0;
    for (auto i = tmp.begin(); i != tmp.end(); i++)
        if (*(i + 1) == 'C' and *i <= '9')
        {
            flag = 1;
            break;
        }
    if (flag)
    {
        tmp.erase(tmp.begin());
        int rr = 0, cc = 0;
        string::iterator it = tmp.begin();
        for (; *it != 'C'; it++)
        {
            rr *= 10;
            rr += (*it) ^ 48;
        }
        it++;
        for (; it != tmp.end(); it++)
        {
            cc *= 10;
            cc += (*it) ^ 48;
        }
        cout << _10_27(cc) << rr << endl;
    }
    else
    {
        int rr = 0, cc = 0;
        string t1, t2;
        for (int i = 0; i < tmp.length(); i++)
            if (tmp[i] < 'A')
            {
                t1 = tmp.substr(0, i);
                t2 = tmp.substr(i, tmp.length());
                break;
            }
        cout << "R" << t2 << "C" << _27_10(t1) << endl;
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s2(a[i]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}