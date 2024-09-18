#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> G, H;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    G.assign(n, {});
    H.assign(n, {});
    
    int mg;
    cin >> mg;
    for (int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int mh;
    cin >> mh;
    for (int i = 0; i < mh; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        H[u].push_back(v);
        H[v].push_back(u);
    }

    vector A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> A[i][j];
        }
    }

    

    return 0;
}