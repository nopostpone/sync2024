#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e5 + 10;
vector<int> a;
bitset<N> bs;

void solve()
{
    char ch = getchar();
    int p = 1;
    for (int i = 40005; i > 0; i--)
    {
        if (ch == '1')
            bs[p++] = 1;
        else if (ch == '0')
            bs[p++] = 0;
        ch = getchar();
    }
    a.push_back(sqrt(--p));
    if (bs[1])
        a.push_back(0);
    int j = 0;
    for (int i = 1; i <= p; i++)
    {
        if (bs[i] != bs[i + 1])
        {
            a.push_back(i - j);
            j = i;
        }
    }
    if (!bs[p])
        for (int i = p;; i--)
            if (bs[i] || !i)
            {
                a.push_back(p - i);
                break;
            }

    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
        cout << *it << ' ';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}