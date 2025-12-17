#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 5e5 + 100;

string a, b;
vector<ll> res;

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a >> b;
        int l, r;
        l = 0;
        while (l < a.length())
        {
            if (a[l] != b[l])
            {
                for (r = l; r < a.length(); r++)
                {
                    if (a[r] == b[r])
                        break;
                }
                if (r - l > 0)
            }
        }
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