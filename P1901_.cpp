// luogu P1901
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
stack<unsigned> sk, sk2, sk3;
unsigned h[N], v[N], r[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> h[i] >> v[i];
    for (i = 1; i <= n; i++)
    {
        while (!sk.empty() && h[i] >= h[sk.top()])
            sk.pop();
        if (!sk.empty())
        {
            r[sk.top()] += v[i];
        }
        sk.push(i);
    }
    for (i = n; i > 0; i--)
    {
        while (!sk2.empty() && h[i] >= h[sk2.top()])
            sk2.pop();
        if (!sk2.empty())
        {
            r[sk2.top()] += v[i];
        }
        sk2.push(i);
    }
    for (i = 1; i <= n; i++)
    {
        if (sk3.empty() || r[i] > sk3.top())
            sk3.push(r[i]);
    }
    cout << sk3.top() << '\n';
    return 0;
}