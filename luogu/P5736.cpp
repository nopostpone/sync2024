// P5736 质数筛
// https://www.luogu.com.cn/problem/P5736
// 输入 n 个不大于 1e5 的正整数。要求全部储存在数组中，去除掉不是质数的数字，依次输出剩余的质数。
// 埃氏筛（Eratosthenes）
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e6 + 100;

bool Isprime[N];
int a[N];
vector<int> res;
vector<int>::iterator it;

void prime(int n)
{
    for (int i = 1; i <= n; i++)
        Isprime[i] = 1;
    Isprime[0] = 0, Isprime[1] = 0;
    for (int i = 2; i <= n; i++)
        if (Isprime[i])
            for (int j = i * 2; j <= n; j += i)
                Isprime[j] = 0;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    prime(1e5);
    // for (int i = 1; i <= n; i++)
    //     cout << Isprime[i] << " \n"[i == 10];
    for (int i = 1; i <= n; i++)
        if (Isprime[a[i]])
            res.push_back(a[i]);
    for (it = begin(res); it != end(res); it++)
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