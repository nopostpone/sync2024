// P3741
// https://www.luogu.com.cn/problem/P3741
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e6 + 100;

string s;
string::iterator it;
ll num = 0;

void solve()
{
    int n;
    cin >> n;
    cin >> s;
    for (it = begin(s) + 1; it != end(s); it++)
        if (*it == 'K' and *(it - 1) == 'V')
            *it = 'J', *(it - 1) = 'A', num++;
    for (it = begin(s) + 1; it != end(s); it++)
        if (*it == *(it - 1))
        {
            num++;
            break;
        }
    cout << num;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}