#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e5 + 10;

bool a[N];
int n;
string str;
int c1, c0;
vector<int> res;

void solve()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> str;
        bool ok = false;
        c1 = 0, c0 = 0;
        for (auto &i : str)
        {
            if (i == '1')
            {
                c1++, ok = false;
            }
            else if (i == '0')
            {
                if (ok)
                    continue;
                c0++, ok = true;
            }
        }
        res.push_back(c1 > c0);
    }
    for (auto &i : res)
    {
        if (i)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
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