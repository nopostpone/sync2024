#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int a[27];

void solve()
{
    char ch;
    int num = 0;
    bool shei = 0;
    while (cin >> ch)
        if (ch <= 'z' and ch >= 'a')
            a[(ch) ^ 96]++, num++;

    int si=0;
    for(int i=1;i<=26;i++)
        if(a[i]&1)si++;
    if(si&1 or si==0)shei=1;
    if(shei)
        cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}