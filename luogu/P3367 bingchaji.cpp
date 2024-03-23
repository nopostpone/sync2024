#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const int N = 1e4 + 10;
int pre[N];
vector<char> r;

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void merge(int x, int y)
{
    pre[root(x)] = root(y);
}

bool iscon(int x, int y)
{
    return root(x) == root(y);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int z, x, y;
    for (int i = 1; i <= n; i++)
        pre[i] = i;
    for (int i = 1; i <= m; i++)
    {
        cin >> z >> x >> y;
        if (z == 1)
            merge(x, y);
        else
        {
            if (iscon(x, y))
                r.push_back('Y');
            else
                r.push_back('N');
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << pre[i] << ' ' << root(i) << endl;
    for (auto &i : r)
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