#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        deg[u]++;
        deg[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] > 3) {
            cout << 0 << "\n";
            return 0;
        }
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (deg[i] > 2) {
            ans--;
        }
    }

    cout << ans << "\n";

    return 0;
}