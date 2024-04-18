// P1308
// https://www.luogu.com.cn/problem/P1308
// 给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。
//
// 比较搞的一道题
// 这里老老实实模拟了
// 看了题解，还有许多做法
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e6 + 100;

string s1, s, tmp;
string::iterator it;
int st = inf, num, len;

bool IsEqual(char a, char b)
{
    // cout << a << b << endl;
    if (a + 32 == b or b + 32 == a or a == b)
        return true;
    return false;
}

void count(int idx)
{
    // cout << "tmp=" << tmp << endl;
    // cout << "s1=" << s1 << endl;
    if (*(tmp.end() - 1) == ' ')
        tmp.pop_back();
    if (tmp.length() != len)
    {
        // cout << "11" << tmp.length();
        return;
    }
    for (int i = 0; i < len; i++)
        if (!IsEqual(s1[i], tmp[i]))
        {
            // cout << s1[i] << ' ' << tmp[i];
            return;
        }
    if (st > idx)
        st = idx;
    num++;
}

void solve()
{
    getline(cin, s1);
    getline(cin, s);
    len = s1.length();
    for (it = begin(s); it != end(s); it++)
    {
        // cout << *it;
        if (*it != ' ')
            tmp.push_back(*it);
        if ((*it == ' ' or it == end(s) - 1) and !tmp.empty())
            count(it - begin(s) - tmp.length()), tmp.clear();
    }
    // cout << endl;
    if (num)
        cout << num << ' ' << st;
    else
        cout << -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}