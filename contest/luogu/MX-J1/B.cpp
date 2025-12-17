#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

ll bb[N];
vector<ll> res;

void solve()
{
    ll a, b, c, n, m;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> c;
        bool f = 0;
        for (int i = 1; i <= 10000; i++)
        {
            bb[i] = a / i;
            if (bb[i] == 1)
            {
                break;
            }
        }
        for (int i = 1; i <= 10000; i++)
        {
            for (int j = bb[i]; j; j--)
            {
                if (bb[i] / j == c)
                {
                    f = 1;
                    res.push_back(bb[i]);
                    break;
                }
            }
            if (bb[i] == 1)
                break;
            if (f)
                break;
        }
        if (!f)
            res.push_back(-1);
    }
    for (auto &i : res)
        cout << i << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}