#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            a[i][j] = a[j][i];
        }
    }

    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = a[1][i];
    }

    vector lca(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            lca[i][j] = f[i] xor f[j] xor a[i][j];
            assert(lca[i][j] > 0 and lca[i][j] <= n);
        }
    }
    
    vector anc(n + 1, vector<bool>(n + 1));
    vector<int> dep(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            anc[i][lca[i][j]] = true;
        }
        dep[i] = count(anc[i].begin(), anc[i].end(), true) - 1;
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return dep[i] < dep[j];
    });

    vector<int> p(n + 1);
    vector<vector<int>> vec(1 << 11);
    for (auto i : ord) {
        if (i != 1) {
            int tar = f[i] xor i;
            for (int j = vec[tar].size() - 1; j >= 0; j--) {
                if (anc[i][vec[tar][j]]) {
                    p[i] = vec[tar][j];
                    break;
                }
            }
        }
        vec[f[i]].push_back(i);
    }
    
    for (int i = 2; i <= n; i++) {
        cout << i << " " << p[i] << "\n";
    }

    return 0;
}

/*
2
1 3
2
*/

/*
4
1 3 2 5
2 0 7
3 6
4
*/

/*
6
1 7 4 5 2 3
2 1 6 7 0
3 5 4 3
4 3 2
5 5
6
*/

/*
6
1 3 2 7 4 1
2 0 6 5 0
3 4 1 7
4 7 2
5 2
6
*/