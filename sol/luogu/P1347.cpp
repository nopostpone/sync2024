#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector adj(n, vector<int>());
    vector adj1(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        adj1[i][i] = true;
    }

    bool ok = false;

    for (int time = 1; time <= m; time++) {
        string s;
        cin >> s;
        int a = s[0] - 'A';
        int b = s[2] - 'A';
        if (s[1] == '<') {
            adj[a].push_back(b);
            adj1[a][b] = true;
        } else {
            adj[b].push_back(a);
            adj1[b][a] = true;
        }

        vector<int> seq;
        auto work = [&]() {
            vector<int> in(n);
            for (int i = 0; i < n; i++) {
                for (auto j : adj[i]) {
                    in[j]++;
                }
            }
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (in[i] == 0) {
                    q.push(i);
                }
            }
            vector<int> vis(n);
            while (not q.empty()) {
                int u = q.front();
                q.pop();
                seq.push_back(u);
                vis[u] = true;
                for (auto v : adj[u]) {
                    if (vis[v]) {
                        return false;
                    }
                    in[v]--;
                    if (in[v] == 0) {
                        q.push(v);
                    }
                }
            }
            return seq.size() == n;
        };


        if (work()) {
            bool okk = true;
            auto f(adj1);
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        f[i][j] = f[i][j] | (f[i][k] and f[k][j]);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (not(f[i][j] or f[j][i])) {
                        okk = false;
                    }
                }
            }
            if (okk) {
                cout << "Sorted sequence determined after " << time << " relations: ";
                for (auto i : seq) {
                    cout << char(i + 'A');
                }
                cout << "." << endl;
                ok = true;
                break;
            }
        } else {
            cout << "Inconsistency found after " << time << " relations.";
            ok = true;
            break;
        }
    }
    if (not ok) {
        cout << "Sorted sequence cannot be determined.";
    }
    
    return 0;
}

