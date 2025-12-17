// https://www.luogu.com.cn/problem/P4447
// 贪心或者二分都能做，这里用了贪心
// 思路参考：https://www.luogu.com.cn/article/6bk13dsc
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e6 + 100;

typedef map<int, int>::iterator it;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

map<int, int> mp;
ll sum = inf;

void huaxian()
{
    it i = mp.begin(), j = i;
    j++;
    --(*i).second;
    int tmpsum = 1;
    for (; j != mp.end() && (*j).second > (*i).second && (*j).first == (*i).first + 1; j++, i++)
        tmpsum++, --(*j).second;
    i = mp.begin();
    while (i != mp.end() && (*i).second == 0)
        mp.erase((*i++).first);
    if (tmpsum < sum)
        sum = tmpsum;
}

void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++)
        ++mp[read()];
    while (!mp.empty())
        huaxian();
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}