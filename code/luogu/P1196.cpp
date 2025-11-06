#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 30000;

    vector<int> dis(n), f(n), siz(n, 1);
    iota(f.begin(), f.end(), 0);

    auto Find = [&](auto &&self, int x) -> int {
        if (f[x] == x) {
            return x;
        }
        int rt = self(self, f[x]);
        dis[x] += dis[f[x]];
        return f[x] = rt;
    };
    auto Merge = [&](int x, int y) {
        f[y] = x;
        siz[x] += siz[y];
    };
    auto Same = [&](int x, int y) {
        return Find(Find, x) == Find(Find, y);
    };

    int q;
    for (cin >> q; q--;) {
        char o;
        int x, y;
        cin >> o >> x >> y;

        if (o == 'M') {
            x = Find(Find, x);
            y = Find(Find, y);
            dis[x] += siz[y];
            Merge(y, x);
        } else {
            int ans = -1;
            if (Same(x, y)) {
                ans = abs(dis[x] - dis[y]) - 1;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}