#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

ll n, k, opt;
vector<ll> res;
int op[100];
ll fst, snd, dis;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int opt;
        fst = 1;
        snd = 2;
        dis = 1;
        while (k--)
        {
            cin >> opt;
            dis *= 2;
            if (opt == 2)
                snd = fst + dis;
            else
            {
                fst = snd;
                snd = snd + dis;
            }
        }
        res.push_back(fst);
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