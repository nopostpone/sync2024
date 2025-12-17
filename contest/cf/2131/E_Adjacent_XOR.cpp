#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    queue<int> q;
    vector<bool> vis(n);
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] ^ a[i + 1]) == b[i]) {
            vis[i] = true;
            q.push(i);
        }
    }
    while (not q.empty()) {
        int i = q.front();
        q.pop();
        a[i] ^= a[i + 1];

        if (i > 0) {
            int j = i - 1;
            if (vis[j]) {
                continue;
            }
            if ((a[j] ^ a[i]) == b[j]) {
                vis[j] = true;
                q.push(j);
            }
        }
    }
    cout << (a == b ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}