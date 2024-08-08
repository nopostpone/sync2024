#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector adj(n, vector<int>());
    vector<int> dfn(n, -1), low(n), bel(n, -1), stk;
    int cur = 0;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        j--;
        while (~j) {
            adj[i].push_back(j);
            cin >> j;
            j--;
        }
    }

    function<void(int)> dfs = [&](int u) {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);

        for (auto v : adj[u]) {
            if (dfn[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (bel[v] == -1) {
                low[u] = min(low[u], low[v]);
            }
        }

        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.back();
                bel[v] = cnt;
                stk.pop_back();
            } while (v != u);
            cnt++;
        }
    };

    for (int i = 0; i < n; i++) {
        if (dfn[i] == -1) {
            dfs(i);
        }
    }

    vector<int> in(cnt), out(cnt);

    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) {
            if (bel[u] == bel[v])
                continue;
            out[bel[u]]++;
            in[bel[v]]++;
        }
    }

    int A = 0, B = 0;
    for (int i = 0; i < cnt; i++) {
        A += in[i] == 0;
        B += out[i] == 0;
    }
    cout << A << endl;
    if (cnt == 1) {
        cout << 0 << endl;
    } else {
        cout << max(A, B) << endl;
    }
    return 0;
}