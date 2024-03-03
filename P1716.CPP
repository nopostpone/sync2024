// luogu P1716 240209
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 5;
ll a[N], b[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, i;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (i = 1; (2 * i - 1) <= n; ++i)
        b[i * 2 - 1] = a[n - i + 1];
    for (i = n % 2 == 0 ? 0.5 * n : 0.5 * (n + 1); i > 0; i--)
        b[2 * i] = a[i];
    for (i = 1; i <= n; ++i)
        cout << b[i] << '\n';
    return 0;
}