// https://codeforces.com/contest/1/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read()
{
    int x = 0, f = 1;
    char ch = nc();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = nc();
    }
    return x * f;
}
void write(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

string a[N];

string s3(int col)
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

int s4(string str)
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
        cout << s3(cc) << rr << endl;
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
        cout << "R" << t2 << "C" << s4(t1) << endl;
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