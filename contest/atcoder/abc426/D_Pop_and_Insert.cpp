#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr void chmax(auto &a, auto b) {
    if (b > a) {
        a = b;
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 2 * n;
    auto work = [&]() {
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }
        
        if (pos.empty()) {
            ans = 0;
            return;
        }
        int res = 2 * n - pos.size();

        int con = 0;
        chmax(con, pos.front());
        chmax(con, n - pos.back() - 1);
        for (int i = 1; i < pos.size(); i++) {
            chmax(con, pos[i] - pos[i - 1] - 1);
        }
        res -= con * 2;

        ans = min(ans, res);
    };
    work();
    for (auto &c : s) {
        c ^= 1;
    }
    work();

    cout << ans << "\n";
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