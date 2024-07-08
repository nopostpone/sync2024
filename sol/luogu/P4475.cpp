// https://www.luogu.com.cn/problem/P4475
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

const int K = 2;

int n, m;
struct node
{
    int d[K];
    int mx[K], mn[K];
    int ls, rs;
    int val;
    int sum;
} t[N], ori[N];

bool cmp(const node &a, const node &b)
{
}

void solve()
{
    cin >> n >> m;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}