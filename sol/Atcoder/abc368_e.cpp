#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, X;
    cin >> n >> m >> X;

    vector<int> a(m), b(m);
    vector<array<int, 3>> e; // {time, leave, id}
    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> a[i] >> b[i] >> s >> t;
        e.push_back({s, 1, i});
        e.push_back({t, 0, i});
    }
    sort(e.begin(), e.end());

    vector<int> ans(m);
    ans[0] = X;

    vector<int> late(n);
    for (auto &&[time, leave, id] : e) {
        int u = a[id] - 1, v = b[id] - 1;
        if (leave == 0) {
            late[v] = max(late[v], ans[id] + time);
        } else {
            // if (id == 0) continue;
            ans[id] = max(ans[id], late[u] - time);
        }
    }

    for (int i = 1; i < m; i++)
        cout << ans[i] << " ";

    return 0;
}
