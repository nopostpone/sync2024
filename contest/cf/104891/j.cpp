#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        adj[i].push_back((i + 1) % n);
        adj[i].push_back((i + a[i]) % n);
    }
    adj[n].push_back(a[0]);

    vector<int> f(n + 1, inf);
    f[n] = 0;

    queue<int> q;
    q.push(n);

    while (not q.empty()) {
        auto x = q.front();
        q.pop();

        for (auto y : adj[x]) {
            if (f[x] + 1 < f[y]) {
                f[y] = f[x] + 1;
                q.push(y);
            }
        }
    }
    cout << f[x] << endl;

    return 0;
}
