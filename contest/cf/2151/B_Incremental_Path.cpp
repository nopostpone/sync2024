#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    set<int> black(a.begin(), a.end());

    auto nxt = [&](int cur) {
        cur++;
        while (black.contains(cur)) {
            cur++;
        }
        return cur;
    };

    int x = 1, y = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            x = nxt(x);
            y = nxt(x);
        } else {
            x++;
            y++;
        }
        black.insert(x);
        x = y;
    }
    cout << black.size() << "\n";

    for (auto x : black) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}