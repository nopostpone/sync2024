#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int fac(int x) {
    int res = 1;
    for (int i = 2; i <= x; i++) {
        res *= i;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector G(n, vector<bool>(n)), H(G);
    
    int mg;
    cin >> mg;
    for (int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[min(u, v)][max(u, v)] = true;
    }

    int mh;
    cin >> mh;
    for (int i = 0; i < mh; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        H[min(u, v)][max(u, v)] = true;
    }

    vector A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    vector p0(p);

    int res = 2e9, T = fac(n);
    while (T--) {
        int t = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int u = min(p[i], p[j]);
                int v = max(p[i], p[j]);
                if (G[i][j] xor H[u][v]) {
                    t += A[u][v];
                }
            }
        }
        res = min(res, t);
        next_permutation(p.begin(), p.end());
    }

    cout << res << endl;

    return 0;
}