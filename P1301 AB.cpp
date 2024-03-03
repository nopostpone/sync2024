#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s1, s2, t, r;

string stradd(string s1, string s2)
{
    string str;
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 < len2)
    {
        for (int i = 1; i <= len2 - len1; i++)
            s1 = "0" + s1;
    }
    else
    {
        for (int i = 1; i <= len1 - len2; i++)
            s2 = "0" + s2;
    }
    len1 = s1.length();
    int cf = 0;
    int temp;
    for (int i = len1 - 1; i >= 0; i--)
    {
        temp = s1[i] - '0' + s2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp ^ 48) + str;
    }
    if (cf != 0)
        str = char(cf ^ 48) + str;
    return str;
}

void solve()
{
    cin >> s1 >> s2;
    if (s1 == "0" || s2 == "0")
    {
        cout << 0;
        exit(0);
    }
    int len1 = s1.length(), len2 = s2.length();
    int i, j, temp, jin;
    r = "0";
    int zero = 0;
    jin = 0;
    for (i = len2 - 1; i >= 0; i--)
    {
        t.clear();
        for (j = len1 - 1; j >= 0; j--)
        {
            temp = (s1[j] ^ 48) * (s2[i] ^ 48) + jin;
            jin = temp / 10;
            temp %= 10;
            t = char(temp ^ 48) + t;
        }
        if (jin > 0)
        {
            t = char(jin ^ 48) + t;
        }
        for (j = 1; j <= zero; j++)
        {
            t = t + "0";
        }
        zero++;
        r = stradd(r, t);
    }
    cout << r;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}