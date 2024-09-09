#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;
using ull = unsigned long long;

map<int, int> ans;

constexpr int n = 25;

vector<int> around(int i) {
    vector<int> p;
    if (i == 0) {
        p = {i, i + 1, i + 5};
    } else if (i == 4) {
        p = {i, i - 1, i + 5};
    } else if (i == 20) {
        p = {i, i + 1, i - 5};
    } else if (i == 24) {
        p = {i, i - 1, i - 5};
    } else if (0 < i and i < 4) {
        p = {i, i - 1, i + 1, i + 5};
    } else if (20 < i and i < 24) {
        p = {i, i - 1, i + 1, i - 5};
    } else if (i % 5 == 0) {
        p = {i, i + 1, i - 5, i + 5};
    } else if ((i + 1) % 5 == 0) {
        p = {i, i - 1, i - 5, i + 5};
    } else {
        p = {i, i - 1, i + 1, i - 5, i + 5};
    }
    return p;
}

void solve() {
    string s, t;
    for (int i = 0; i < 5; i++) {
        cin >> t;
        s = s + t;
    }

    int s0 = 0;
    for (int i = 0; i < n; i++) {
        s0 += (s[i] == '1') << i;
    }

    if (ans.contains(s0)) {
        cout << ans[s0] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int S = (1 << 25) - 1;

    queue<pair<int, int>> q;
    q.push({S, 0});
    ans[S] = 0;

    while (!q.empty()) {
        auto [now, cost] = q.front();
        q.pop();

        if (cost > 5) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int nxt = now;
            auto p = around(i);
            for (auto x : p) {
                if ((nxt >> x) & 1) {
                    nxt -= 1 << x;
                } else {
                    nxt += 1 << x;
                }
            }
            if (not ans.contains(nxt)) {
                // dbg(nxt);
                ans[nxt] = cost + 1;
                q.push({nxt, cost + 1});
            }
        }
    }

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}