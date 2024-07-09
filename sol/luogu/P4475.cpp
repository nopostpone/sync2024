// https://www.luogu.com.cn/problem/P4475
// K - D树模板
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const ll N = 1e5 + 100;

const ll K = 2;

ll n, m;
ll a, b, c;
struct node
{
    ll d[K];
    ll mx[K], mn[K];
    ll ls, rs;
    ll val;
    ll sum;
} t[N], ori[N];

ll tk;

bool cmp(const node &a, const node &b)
{
    return a.d[tk] < b.d[tk];
}

void update(ll p)
{
    ll ls = t[p].ls, rs = t[p].rs;
    for (ll i = 0; i < K; i++)
    {
        t[p].mx[i] = t[p].mn[i] = t[p].d[i];
        if (ls)
        {
            t[p].mx[i] = max(t[p].mx[i], t[ls].mx[i]);
            t[p].mn[i] = min(t[p].mn[i], t[ls].mn[i]);
        }
        if (rs)
        {
            t[p].mx[i] = max(t[p].mx[i], t[rs].mx[i]);
            t[p].mn[i] = min(t[p].mn[i], t[rs].mn[i]);
        }
    }
    t[p].sum = t[ls].sum + t[rs].sum + t[p].val;
}

ll build(ll l, ll r, ll k)
{
    if (l > r)
        return 0;
    ll mid = (l + r) >> 1;
    tk = k;
    nth_element(ori + l, ori + mid, ori + r + 1, cmp);
    t[mid] = ori[mid];
    t[mid].ls = build(l, mid - 1, k ^ 1);
    t[mid].rs = build(mid + 1, r, k ^ 1);
    update(mid);
    return mid;
}

ll check(ll x, ll y)
{
    return a * x + b * y < c;
}

ll query(ll x)
{
    ll tmp = 0;
    tmp += check(t[x].mx[0], t[x].mx[1]);
    tmp += check(t[x].mn[0], t[x].mx[1]);
    tmp += check(t[x].mx[0], t[x].mn[1]);
    tmp += check(t[x].mn[0], t[x].mn[1]);
    if (tmp == 4)
        return t[x].sum;
    if (tmp == 0)
        return 0;
    ll ans = 0;
    if (check(t[x].d[0], t[x].d[1]))
        ans += t[x].val;
    if (t[x].ls)
        ans += query(t[x].ls);
    if (t[x].rs)
        ans += query(t[x].rs);
    return ans;
}

vector<ll> res;

void solve()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> ori[i].d[0] >> ori[i].d[1] >> ori[i].val;
    }
    ll root = build(1, n, 0);
    for (ll i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        res.push_back(query(root));
    }
    for (auto &i : res)
        cout << i << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll _ = 1;
    while (_--)
        solve();
    return 0;
}