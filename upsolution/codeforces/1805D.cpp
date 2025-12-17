#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> dep1, dep2;

void dfs1(int u, int fa) {
    for (auto v : adj[u]) {
        if (v != fa) {
            dep1[v] = dep1[u] + 1;
            dfs1(v, u);
        }
    }
}

void dfs2(int u, int fa) {
    for (auto v : adj[u]) {
        if (v != fa) {
            dep2[v] = dep2[u] + 1;
            dfs2(v, u);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    adj.assign(n, {});
    dep1.resize(n, 0);
    dep2.resize(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0, -1);
    int U = max_element(dep1.begin(), dep1.end()) - dep1.begin();

    dep1[U] = 0;
    dfs1(U, -1);

    int V = max_element(dep1.begin(), dep1.end()) - dep1.begin();
    dfs2(V, -1);

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (i == U) {
            continue;
        }
        int d = std::max(dep1[i], dep2[i]);
        res[d]++;
    }
    res[0]++;
    for (int i = 1; i < n; i++) {
        res[i] += res[i - 1];
    }
    for (auto i : res) {
        cout << i << " ";
    }

    return 0;
}