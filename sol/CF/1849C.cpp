#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<int> nxt(n + 1, n), lst(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = (s[i] == '1' ? i : nxt[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        lst[i + 1] = (s[i] == '0' ? i : lst[i]);
    }

    unordered_set<i64> vis;

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;
        l = nxt[l];
        r = lst[r];
        if (l > r) {
            l = r = -1;
        }
        vis.insert(1ll * l * n + r);
    }
    cout << vis.size() << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}