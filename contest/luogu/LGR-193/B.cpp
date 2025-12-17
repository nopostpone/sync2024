#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e5 + 100;

string a, b;
vector<ll> res;

bool is(int l, int r, const string &str)
{
    for (int i = l; i <= r; i++)
    {
        if (str[i] != b[i])
            return false;
    }
    return true;
}

string gai(int l, int r, int x)
{
    string tmp = a;
    if (x == 1)
    {
        for (int i = l; i <= r; i++)
        {
            if (tmp[i] == '0')
                tmp[i] = '1';
            else
                tmp[i] = '0';
        }
    }
    else if (x == 2)
    {
        for (int i = l; i <= r; i++)
        {
            tmp[i] = '0';
        }
    }
    else if (x == 3)
    {
        for (int i = l; i <= r; i++)
        {
            tmp[i] = '1';
        }
    }
    return tmp;
}

void solve()
{
    int n;
    int cnt = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a >> b;
        int lpos = 0, rpos = a.length() - 1;
        while (a[lpos] == b[lpos])
            lpos++;
        while (a[rpos] == b[rpos])
            rpos--;
        if (lpos >= rpos)
        {
            res.push_back(0);
            return;
        }
        while (1)
        {
            cnt++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}