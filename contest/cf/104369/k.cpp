#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> pos(k);
    for (auto &[x, y] : pos) {
        cin >> x >> y;
        x--;
        y--;
    }

    auto conv = [&](int i) {
        return pair(i / m, i % m);
    };

    unordered_set<u64> vis;
    int ans = k;
    auto dfs = [&](this auto &&self, u64 s) -> void {
        ans = min(ans, (int)popcount(s));

        for (int i = 0; i < 36; i++) {
            if (s >> i & 1) {
                auto [x, y] = conv(i);
                for (int mod = 0; mod < 4; mod++) {
                    int nx = x + dx[mod];
                    int ny = y + dy[mod];
                    int nx2 = nx + dx[mod];
                    int ny2 = ny + dy[mod];
                    if (nx2 < 0 or ny2 < 0 or nx2 >= n or ny2 >= m) {
                        continue;
                    }

                    auto skip = nx * m + ny;
                    auto ed = nx2 * m + ny2;
                    if (~s >> skip & 1) {
                        continue;
                    }
                    if (s >> ed & 1) {
                        continue;
                    }
                    u64 ns = s;
                    ns -= 1ull << skip;
                    ns -= 1ull << i;
                    ns |= 1ull << ed;
                    
                    vis.insert(ns);
                    self(ns);
                }
            }
        }
    };

    u64 ori = 0;
    for (auto [x, y] : pos) {
        ori |= 1ll << (x * m + y);
    }
    vis.insert(ori);
    dfs(ori);

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
}
/*
3
3 4 5
2 2
1 2
1 4
3 4
1 1
1 3 3
1 1
1 2
1 3
2 1 1
2 1
*/