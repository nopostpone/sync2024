// B3948
// https://www.luogu.com.cn/problem/B3948
// 给定一些多选题的答案和作答，加入你从第 x 题开始作答，判断你可以拿到多少分。
// 题不难，逻辑有点搞，我当时卡住了
// 而且我漏判断了四个选项都是 0 的情况
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050;
bool a[N][5], b[N][5];
int res[N];

int check(int x, int y)
{
    bool f = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (b[y][i] == 1)
        {
            f = 1;
            break;
        }
    }
    if (!f)
        return 0;
    f = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (a[x][i] == 0 && b[y][i] == 1)
        {
            // cout << 0 << endl;
            return 0;
        }
        if (a[x][i] == 1 && b[y][i] == 0)
            f = 1;
    }
    // cout << (f ? 3 : 6) << endl;
    return f ? 3 : 6;
}

int main()
{

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(res, sizeof(res), 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= 4; j++)
            cin >> b[i][j];

    for (int x = 0; x < n; x++)
    {
        for (int i = 0; i < n; i++)
        {
            // cout << "qwq" << (i + x) % n << endl;
            res[x] += check((i + x) % n, i);
        }
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    return 0;
}