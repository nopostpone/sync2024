#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

const int p = 998244353;
ll a, x;
ll tmp;
vector<ll> res;

void solve()
{
    int q;
    cin >> q;
    while (q--)
    {
        cin >> a >> x;
        a %= p;
        if (x == 1)
            tmp = a;
        else
        {
            tmp = x;
            tmp = ((tmp * (x - 1)) / 2) % p;
            tmp = (tmp * a) % p;
            tmp = (tmp * a) % p;
        }
        res.push_back(tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    for (auto &i : res)
    {
        cout << i << endl;
    }
    return 0;
}