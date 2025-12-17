#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int n, L, R;
string str;
int c1[N], c0[N];
int cnt, cnt2;

void solve()
{
    cin >> n >> L >> R;
    cin >> str;
    int st = 0, ed = n + 1;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
            c0[i + 1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        c0[i] = c0[i - 1] + c0[i];
    }
    for (int i = n - 1; i > -1; i--)
    {
        if (str[i] == '1')
            c1[i + 1] = 1;
    }
    for (int i = n; i; i--)
    {
        c1[i] = c1[i + 1] + c1[i];
    }
    for (int i = 0; i < n; i++)
    {
        int now = i + 1;
        int tmp = abs(c0[now] - c0[st] - c1[now + 1]);
        if (L <= tmp and tmp <= R)
            st = i, cnt++;
    }
    for (int i = n; i; i--)
    {
        int tmp = abs(c0[i - 1] - c1[i] + c1[ed]);
        if (L <= tmp and tmp <= R)
            ed = i, cnt2++;
    }
    cout << max(cnt, cnt2) << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}