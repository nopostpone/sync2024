// luogu P10058 2402 _
// https://www.luogu.com.cn/problem/P10058
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
string S, temp;
ll last;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i = 1;
    int q;
    unsigned x = 1000;

    bool IsZheng = 1;
    cin >> S;
    cin >> q;

    string question;
    int lg = S.length();
    while (q--)
    {
        cin >> question;
        if (question == "rev")
        {
            IsZheng = !IsZheng;
        }
        else if (question == ">")
        {
            cin >> x;
            x = x % lg;
            if (IsZheng)
                last += x;
            else
                last -= x;
        }
        else if (question == "<")
        {
            cin >> x;
            x = x % lg;
            if (IsZheng)
                last -= x;
            else
                last += x;
        }
    }

    temp = S;
    if (last > 0)
    {
        last = last % lg;
        S.erase(S.begin(), S.end() - last);
        S.append(temp.begin(), temp.end() - last);
    }
    else if (last < 0)
    {
        last = -last;
        last = last % lg;
        S.erase(S.begin(), S.begin() + last);
        S.append(temp.begin(), temp.begin() + last);
    }
    if (!IsZheng)
        reverse(S.begin(), S.end());

    cout << last << '\n';

    return 0;
}