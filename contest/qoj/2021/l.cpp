#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), in(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        in[a[i]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    vector<bool> vis(n);

    int ans = 0;
    while (not q.empty()) {
        int x = q.front();
        q.pop();
        ans++;
        vis[x] = true;

        int y = a[x];
        if (not vis[y]) {
            vis[y] = true;
            int z = a[y];
            in[z]--;
            if (in[z] == 0) {
                q.push(z);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }

        int len = 0;
        for (int x = i; not vis[x]; x = a[x]) {
            vis[x] = true;
            len++;
        }
        ans += len / 2;
    }
    cout << ans << "\n";
}