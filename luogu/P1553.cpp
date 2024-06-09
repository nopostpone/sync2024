// https://www.luogu.com.cn/problem/P1553
// 非常搞的模拟
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
    string s;
    cin >> s;
    string::iterator x;
    int flag = 1; // 1-int,2-float,3-a/b,4-%
    for (auto i = s.begin(); i != s.end(); i++)
        if (*i == '.')
            flag = 2, x = i;
        else if (*i == '/')
            flag = 3, x = i;
        else if (*i == '%')
            flag = 4, x = i;
    switch (flag)
    {
    case 1:
        reverse(s.begin(), s.end());
        if (s == "0")
            break;
        if (*(s.begin()) == '0')
            s.erase(s.begin(), s.begin() + s.find_first_not_of('0'));
        break;
    case 2:
        reverse(s.begin(), x);
        reverse(x + 1, s.end());
        s.erase(s.begin(), s.begin() + s.find_first_not_of('0'));
        s.erase(s.begin() + s.find_last_not_of('0') + 1, s.end());
        if (*(s.begin()) == '.')
            s.insert(s.begin(), '0');
        if (*(s.end() - 1) == '.')
            s.push_back('0');
        break;
    case 3:
        reverse(s.begin(), x);
        reverse(x + 1, s.end());
        if (*(x + 1) == '0')
            for (auto i = x + 1; i != s.end();)
                if (*i != '0')
                    break;
                else
                    s.erase(i);
        s.erase(s.begin(), s.begin() + s.find_first_not_of('0'));
        if (*(s.begin()) == '/')
            s.insert(s.begin(), '0');
        break;
    case 4:
        reverse(s.begin(), s.end() - 1);
        s.erase(s.begin(), s.begin() + s.find_first_not_of('0'));
        if (*(s.begin()) == '%')
            s.insert(s.begin(), '0');
    default:
        break;
    }
    cout << s;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}