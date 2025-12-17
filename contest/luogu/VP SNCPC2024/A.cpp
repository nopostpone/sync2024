#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;

int a[N];
string s2(int x)
{
    string str;
    switch (x)
    {
    case 0:
        str = "---";
        break;
    case 1:
        str = "--x";
        break;
    case 2:
        str = "-w-";
        break;
    case 3:
        str = "-wx";
        break;
    case 4:
        str = "r--";
        break;
    case 5:
        str = "r-x";
        break;
    case 6:
        str = "rw-";
        break;
    case 7:
        str = "rwx";
        break;
    default:
        break;
    }
    return str;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int x1 = a[i] / 100;
        int z1 = a[i] % 10;
        int y1 = (a[i] - x1 * 100 - z1) / 10;
        cout << s2(x1) << s2(y1) << s2(z1) << endl;
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