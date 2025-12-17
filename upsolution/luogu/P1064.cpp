#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n, m;
    cin >> m >> n;

    m /= 10;

    vector<array<int, 2>> a(n);
    vector adj(n, vector<int>());

    vector<int> col;    

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][0] /= 10;
        a[i][1] *= a[i][0];
        int q;
        cin >> q;
        if (q) {
            adj[q - 1].push_back(i);
        } else {
            col.push_back(i);
        }
    }

    const int o = col.size();

    vector v(o, vector<int>()), p(v);
    for (int i = 0; i < o; i++) {
        int top = col[i];
        v[i].push_back(a[top][0]);
        p[i].push_back(a[top][1]);

        for (int j = 0; j < adj[top].size(); j++) {
            int t2 = adj[top][j];
            v[i].push_back(a[top][0] + a[t2][0]);
            p[i].push_back(a[top][1] + a[t2][1]);

            for (int k = j + 1; k < adj[top].size(); k++) {
                int t3 = adj[top][k];
                v[i].push_back(a[top][0] + a[t2][0] + a[t3][0]);
                p[i].push_back((a[top][1] + a[t2][1] + a[t3][1]));
            }
        }
    }

    vector<int> dp(m + 1);
    for (int i = 0; i < o; i++) {
        vector<int> ndp(dp);
        int siz = v[i].size();

        for (int k = 0; k < siz; k++) {
            for (int j = 0; j <= m; j++) {
                if (j >= v[i][k]) {
                    ndp[j] = max(ndp[j], dp[j - v[i][k]] + p[i][k]);
                }
            }
        }
        dp = move(ndp);
    }

    cout << dp[m] * 10 << "\n";

    return 0;
}