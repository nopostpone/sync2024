#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e5 + 100;

int n;
int id[N];
stack<int> sk;
vector<int> res;
bool vis[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> id[i];
    }
    for (int i = n; i; i--)
    {
        sk.push(id[i]);
    }
    int now;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        int cnt = 0;
        if (vis[now])
        {
            res.push_back(0);
            continue;
        }
        while (!sk.empty() and sk.top() != now)
        {
            cnt++;
            vis[sk.top()] = 1;
            sk.pop();
        }
        cnt++;
        vis[now] = 1;
        sk.pop();
        res.push_back(cnt);
    }
    for (auto &i : res)
        cout << i << ' ';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}