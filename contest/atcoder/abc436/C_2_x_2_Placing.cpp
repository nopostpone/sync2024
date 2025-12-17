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

    int n, m;
    cin >> n >> m;

    auto encode = [&](int x, int y) {
        return 1ll * x * n + y;
    };

    unordered_set<i64> s;

    int ans = 0;
    for (int _ = 0; _ < m; _++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        array<i64, 4> occ {encode(x, y), encode(x + 1, y), encode(x, y + 1), encode(x + 1, y + 1)};
        bool ok = true;
        for (auto h : occ) {
            if (s.contains(h)) {
                ok = false;
            }
        }
        if (ok) {
            for (auto h : occ) {
                s.insert(h);
            }
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}