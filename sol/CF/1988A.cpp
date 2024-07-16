#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 10;

vector<int> res;

void solve()
{
    int tt;
    cin >> tt;
    int n, k, cnt;
    while (tt--)
    {
        cin >> n >> k;
        cout << (n + k - 3) / (k - 1) << endl;
        // cnt = 0;
        // vector<int> tmp;
        // tmp.push_back(n);
        // while (tmp.size() < n)
        // {
        //     cnt++;
        //     int now = tmp.back();
        //     tmp.pop_back();
        //     if (now < k)
        //     {
        //         while (now--)
        //             tmp.push_back(1);
        //     }
        //     else
        //     {
        //         for (int i = 1; i < k; i++)
        //             tmp.push_back(1);
        //         tmp.push_back(now - k + 1);
        //     }
        // }
        // res.push_back(cnt);
    }
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}