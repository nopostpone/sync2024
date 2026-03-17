#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int x = 0;
    vector<bool> vis(n);
    vis[0] = true;
    for (int i = 0; i < n; i++) {
        x = (s[x] == 'R' ? x + 1 : x - 1);
        vis[x] = true;
    }
    cout << ranges::count(vis, true) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}