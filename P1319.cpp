// luogu p1319 230210
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e2 + 5;
int a[N * N];
int ysm[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // code
    int size, i, j, p;
    bool Is1 = 0;
    cin >> size;
    i = 1;
    p = 1;
    while (cin >> ysm[i])
    {
        for (j = p; j < p + ysm[i]; j++)
            a[j] = Is1;
        p += ysm[i];
        Is1 = !Is1;
        i++;
    }
    for (i = 1; i <= size * size; i++)
    {
        cout << a[i];
        if (i % size == 0)
            cout << '\n';
    }
    //
    return 0;
}