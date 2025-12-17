#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    map<int, int> f;
    for (int j = 0; j < m; j++) {
        int t{};
        for (int i = 0; i < n; i++) {
            t += a[i][j];
        }
        f[t] = j;
    }

    int u = f.rbegin()->second;

    map<int, int> g;
    for (int i = 0; i < n; i++) {
        g[a[i][u]]++;
    }

    cout << g.rbegin()->first << " " << g.rbegin()->second << endl;

    return 0;
}