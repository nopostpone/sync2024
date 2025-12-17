#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

constexpr int inf = 2e9;

std::vector<int> dep, parent;
std::vector<std::vector<int>> adj, rdep;
int maxdep;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs1(int u) {
    if (parent[u] != -1) {
        adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
    }
    for (auto &v : adj[u]) {
        parent[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
    }
    maxdep = max(dep[u], maxdep);
    rdep[dep[u]].push_back(u);
}

void work(int root = 0) {
    dep[root] = 0;
    parent[root] = -1;
    dfs1(root);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    dep.resize(n + 1);
    parent.resize(n + 1);
    adj.assign(n + 1, {});
    rdep.assign(n + 1, {});
    maxdep = -inf;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) {
        int j;
        cin >> j;
        addEdge(j, i);
    }
    work(1);

    queue<int> qu;
    for (int d = maxdep - 1; d; d--) {
        for (auto i : rdep[d]) {
            qu.push(i);
        }
    }
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        int mn = inf;
        for (auto &v : adj[u]) {
            mn = min(a[v], mn);
        }
        if (mn != inf) {
            if (mn < a[u]) {
                a[u] = mn;
            } else {
                a[u] = a[u] + mn >> 1;
            }
        }
    }
    int mn = inf;
    for (auto i : adj[1]) {
        mn = min(a[i], mn);
    }

    cout << a[1] + mn << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}