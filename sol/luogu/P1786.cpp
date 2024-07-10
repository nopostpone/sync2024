#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 110;

struct node
{
    string name;
    int prof, idx, lvl, val;
    bool operator<(const node &o)
    {
        return prof == o.prof ? lvl == o.lvl ? idx < o.idx : lvl > o.lvl : prof < o.prof;
        // return prof == o.prof ? idx < o.idx : prof < o.prof;
    }
} a[N];

int strtoint(string &o)
{
    if (o == "BangZhu")
        return 1;
    else if (o == "FuBangZhu")
        return 2;
    else if (o == "HuFa")
        return 3;
    else if (o == "ZhangLao")
        return 4;
    else if (o == "TangZhu")
        return 5;
    else if (o == "JingYing")
        return 6;
    else
        return 7;
}

string inttostr(int &x)
{
    if (x == 1)
        return "BangZhu";
    else if (x == 2)
        return "FuBangZhu";
    else if (x == 3)
        return "HuFa";
    else if (x == 4)
        return "ZhangLao";
    else if (x == 5)
        return "TangZhu";
    else if (x == 6)
        return "JingYing";
    else
        return "BangZhong";
}

int profmax[] = {0, 0, 0, 2, 4, 7, 25, 0x3f3f3f3f};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name,
            oriprof;
        int val, lvl;
        cin >> name >> oriprof >> val >> lvl;
        a[i] = node{name, strtoint(oriprof), i, lvl, val};
    }
    sort(a + 1, a + 1 + n, [](node &x, node &y)
         { return x.val > y.val; });
    for (int i = 1; i <= n; i++)
    {
        if (a[i].prof < 3)
            continue;
        for (int j = 3; j <= 7; j++)
            if (profmax[j])
            {
                a[i].prof = j;
                profmax[j]--;
                break;
            }
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].name << ' ' << inttostr(a[i].prof) << ' ' << a[i].lvl << endl;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}