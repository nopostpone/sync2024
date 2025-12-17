#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y, res;
        cin >> x >> y;
        x--, y--; 
        if (x % 2 and y % 2 == 0)
            res = 2;
        else if (y % 2 and x % 2 == 0)
            res = 2;
        else if (x % 2 == 0 and y % 2 == 0)
            res = 3;
        else
            res = 3;
        cout << res << endl;
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