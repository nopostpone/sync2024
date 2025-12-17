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

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<bool> vis(n);
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }

        int len = 0;
        for (int j = i; not vis[j]; j = p[j]) {
            len++;
            vis[j] = true;
        }
        ans += 1ll * len * (len - 1) / 2;
    }
    cout << ans << "\n";

    return 0;
}