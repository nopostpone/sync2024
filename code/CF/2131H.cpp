#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int V = 1e6;
vector<int> d[V + 1];
int mu[V + 1];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> f(m + 1);
    for (int i = 0; i < n; i++) {
        for (auto j : d[a[i]]) {
            f[j]++;
        }
    }

    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (auto j : d[a[i]]) {
            deg[i] += mu[j] * f[j];
        }
        deg[i] -= (a[i] == 1);
    }

    int ans[4]{};
    int u = max_element(deg.begin(), deg.end()) - deg.begin();
    if (deg[u] == 0) {
        cout << 0 << "\n";
        return;
    }

    int v = 0, mindeg = n;
    for (int i = 0; i < n; i++) {
        if (i == u or __gcd(a[i], a[u]) != 1) {
            continue;
        }
        deg[i]--;
        if (deg[i] < mindeg) {
            v = i;
            mindeg = deg[i];
        }
    }
    ans[0] = u;
    ans[1] = v;
    deg[u] = deg[v] = 0;
    for (int i = 0; i < n; i++) {
        if (i == u or i == v) {
            continue;
        }
        deg[i] -= __gcd(a[i], a[v]) == 1;
    }

    u = max_element(deg.begin(), deg.end()) - deg.begin();
    if (deg[u] == 0) {
        cout << 0 << "\n";
        return;
    }
    v = 0;
    for (int i = 0; i < n; i++) {
        if (i == u or __gcd(a[i], a[u]) != 1 or i == ans[0] or i == ans[1]) {
            continue;
        }
        v = i;
        break;
    }
    ans[2] = u;
    ans[3] = v;

    for (int i = 0; i < 4; i++) {
        cout << ans[i] + 1 << " \n"[i == 3];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mu[1] = 1;
    for (int i = 1; i <= V; i++) {
        for (int j = i * 2; j <= V; j += i) {
            mu[j] -= mu[i];
        }
    }
    for (int i = 1; i <= V; i++) {
        for (int j = i; j <= V; j += i) {
            d[j].push_back(i);
        }
    }

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}