// P1093
// 非常经典的重载运算符
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const ll inf = pow(2, 31) - 1;
const int N = 1e6 + 100;

struct ren
{
    int a, b, c, order, sum;
    bool operator<(const ren &rhs) const
    {
        return sum != rhs.sum ? sum > rhs.sum : a != rhs.a ? a > rhs.a
                                                           : order < rhs.order;
    }
    void __init__(int i)
    {
        sum = a + b + c;
        order = i;
    }
} a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b >> a[i].c;
    for (int i = 1; i <= n; i++)
        a[i].__init__(i);

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= 5; i++)
        cout << a[i].order << ' ' << a[i].sum << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}