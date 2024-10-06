#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    int pos = 0;
    vector<int> b(n);
    for (int i = n; i; i--) {
        int now = pos + i;
        if (not adj[now].empty()) {
            b[adj[now].back()] = i;
            adj[now].pop_back();
            pos++;
        } else if (not adj[pos].empty()) {
            b[adj[pos].back()] = -i;
            adj[pos].pop_back();
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for_each(b.begin(), b.end(), [](auto i) { cout << i << " "; });
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}