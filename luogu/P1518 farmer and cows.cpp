// P1518 240301
// Finishing the code before learning graph theory, so it's looks clumsy

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 13;
bool Iskong[N][N];
char ch[N][N];
struct location
{
    int x, y;
    int d = 0; // d-> direction:0->up,1->right,2->down,3->left
    bool operator==(const location &rhs)
    {
        return ((x == rhs.x) && (y == rhs.y) && (d == rhs.d));
    }
} f, c;

vector<pair<location, location>> mat;
vector<pair<location, location>>::iterator it;

bool Iszhuang(const location *k)
{
    int px = k->x, py = k->y;
    switch (k->d)
    {
    case 0:
    {
        px--;
        break;
    }
    case 1:
    {
        py++;
        break;
    }
    case 2:
    {
        px++;
        break;
    }
    case 3:
    {
        py--;
        break;
    }
    default:
    {
        cout << "qwq1 " << k->d << endl;
        exit('0');
    }
    }
    if (px < 1 || px > 10 || py < 1 || py > 10 || !Iskong[px][py])
        return true;
    return false;
}

void moni(location *k)
{
    // cout << Iszhuang(k) << endl;
    if (!Iszhuang(k))
    {
        // cout << "uwu" << endl;
        switch (k->d)
        {
        case 0:
        {
            k->x--;
            break;
        }
        case 1:
        {
            k->y++;
            break;
        }
        case 2:
        {
            k->x++;
            break;
        }
        case 3:
        {
            k->y--;
            break;
        }
        default:
        {
            cout << "qwq2" << endl;
            exit('0');
        }
        }
    }
    else
        k->d = (k->d == 3 ? 0 : k->d + 1);
}

bool Isexist(const location a, const location b)
{
    if (!mat.empty())
        for (it = mat.begin(); it != mat.end(); it++)
        {
            if ((*it).first == a && (*it).second == b)
                return true;
        }
    mat.emplace_back(make_pair(a, b));
    return false;
}

void solve()
{
    int t = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            cin >> ch[i][j];
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            if (ch[i][j] != '*')
                Iskong[i][j] = 1;
            if (ch[i][j] == 'F')
                f.x = i, f.y = j;
            if (ch[i][j] == 'C')
                c.x = i, c.y = j;
        }

    while (f.x != c.x || f.y != c.y)
    {
        t++;
        moni(&c);
        moni(&f);
        // cout << f.x << ' ' << f.y << ' ' << f.d << endl;
        // cout << c.x << ' ' << c.y << ' ' << c.d << endl;
        // if (t == 2)
        //     break;
        if (Isexist(f, c))
        {
            cout << 0;
            return;
        }
    }
    cout << t;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
