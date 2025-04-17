#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using p32 = pair<int, int>;
constexpr p32 operator+(p32 a, p32 b) {
    return {a.first + b.first, a.second + b.second};
}
constexpr p32 operator-(p32 a, p32 b) {
    return {a.first - b.first, a.second - b.second};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<p32> pos(n + 1);
    for (int i = 0, x = 0, y = 0; i < n; i++) {
        if (s[i] == 'U') {
            y++;
        } else if (s[i] == 'D') {
            y--;
        } else if (s[i] == 'L') {
            x--;
        } else {
            x++;
        }
        pos[i + 1] = {x, y};
    }

    map<p32, vector<int>> f;
    for (int i = 0; i <= n; i++) {
        f[pos[i]].push_back(i);
    }

    auto get = [&](p32 p, int l, int r) {
        if (not f.contains(p)) {
            return false;
        }
        auto &vec = f[p];
        auto it = lower_bound(vec.begin(), vec.end(), l);
        return it != vec.end() and *it <= r;
    };

    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        l--;

        p32 que = {x, y};
        bool ok = get(que, 0, l) or get(que, r, n) or get(pos[l] + pos[r] - que, l, r);

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}