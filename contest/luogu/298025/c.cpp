#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

string dir = "NESW";

void solve() {
    int n;
    cin >> n;

    vector<pair<char, int>> ans;

    int init = 0;

    int lst = 0;
    for (int i = 0; i < n; i++) {
        char c;
        int d;
        cin >> c >> d;

        int p = dir.find(c);
        if (i == 0) {
            init = p;
        } else {
            if (p == (lst + 1) % 4) {
                ans.emplace_back('R', 0);
            } else {
                ans.emplace_back('L', 0);
            }
        }
        ans.emplace_back('Z', d);
        lst = p;
    }

    cout << ans.size() << " " << dir[init] << "\n";
    for (auto [c, d] : ans) {
        if (c == 'Z') {
            cout << c << " " << d << "\n";
        } else {
            cout << c << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}