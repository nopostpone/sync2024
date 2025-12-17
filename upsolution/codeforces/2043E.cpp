#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    bool ok = true;
    for (int d = 0; d < 30 and ok; d++) {
        vector x(n, vector<array<bool, 2>>(m));
        vector<int> R(n), C(m);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = b[i][j] >> d & 1;
                x[i][j][c] = 1;
                if (c == 0 and ++R[i] == m) {
                    q.push(i);
                }
                if (c == 1 and ++C[j] == n) {
                    q.push(n + j);
                }
            }
        }
        while (not q.empty()) {
            int u = q.front();
            q.pop();

            if (u < n) {
                for (int v = 0; v < m; v++) {
                    if (x[u][v][1] == 0) {
                        x[u][v][1] = 1;
                        if (++C[v] == n) {
                            q.push(n + v);
                        }
                    }
                }
            } else {
                u -= n;
                for (int v = 0; v < n; v++) {
                    if (x[v][u][0] == 0) {
                        x[v][u][0] = 1;
                        if (++R[v] == m) {
                            q.push(v);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (not x[i][j][a[i][j] >> d & 1]) {
                    ok = false;
                }
            }
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}
