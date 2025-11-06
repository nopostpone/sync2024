#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> dep;
vector<bool> leaf;

void dfs(int u, int fa) {
    bool f = true;
    for (int v : adj[u]) {
        if (v != fa) {
            f = false;
            dfs(v, u);
        }
    }
    leaf[u] = f;
}

void init(int n) {
    adj.assign(n, {});
    dep.assign(n, 0);
    leaf.assign(n, false);
}

void solve() {
    int n;
    cin >> n;
    init(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);

    string s;
    cin >> s;

    int L = 0, NL = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '?') {
            if (leaf[i]) {
                L++;
            } else {
                NL++;
            }
        }
    }

    int res = 0;
    if (s[0] == '?') {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (leaf[i] and s[i] != '?') {
                if (s[i] == '1') {
                    x++;
                } else {
                    y++;
                }
            }
        }
        if (x != y) {
            res = std::max(x, y) + L / 2;
        } else {
            if (NL % 2 == 1) {
                res = std::min(x, y) + L / 2 + (L % 2);
            } else {
                res = std::max(x, y) + L / 2;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (leaf[i] and s[i] != '?') {
                res += s[i] != s[0];
            }
        }
        res += (L / 2) + (L % 2);
    }

    cout << res << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}