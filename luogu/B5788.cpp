// luogu P5788
#include <iostream>
#include <stack>
using namespace std;

const int N = 3e6 + 5;
unsigned a[N], r[N];
stack<int> sk;

int main()
{
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = n; i >= 1; i--)
    {
        while (!sk.empty() && a[i] >= a[sk.top()])
            sk.pop();
        r[i] = sk.empty() ? 0 : sk.top();
        sk.push(i);
    }
    for (i = 1; i <= n; i++)
        cout << r[i] << ' ';
    return 0;
}