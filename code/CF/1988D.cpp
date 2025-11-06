#include <bits/stdc++.h>
using namespace std;

#define QwQ01AwA return 0
#define ll long long
#define look_time cerr << 1.0 * clock() / CLOCKS_PER_SEC << '\n'
template <typename T>
void ckmax(T &x, T y) { x = max(x, y); }
template <typename T>
void ckmin(T &x, T y) { x = min(x, y); }

const int N = 3e5 + 5;
const ll inf = 1e18;
int n;
vector<int> e[N];
ll w[N], f[N][105];
const int limk = 100;

void dfs(int u, int fa) {
    for (int i = 1; i <= limk; i++)
        f[u][i] = w[u] * i;
    for (auto v : e[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        ll mn = inf, smn = inf, id = -1;
        for (int i = 1; i <= limk; i++) {
            if (mn > f[v][i])
                smn = mn, mn = f[v][i], id = i;
            else
                ckmin(smn, f[v][i]);
        }
        for (int i = 1; i <= limk; i++) {
            if (i == id)
                f[u][i] += smn;
            else
                f[u][i] += mn;
            ckmin(f[u][i], inf);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        e[i].clear(), cin >> w[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    ll ans = inf;
    for (int i = 1; i <= limk; i++)
        ckmin(ans, f[1][i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    QwQ01AwA;
}