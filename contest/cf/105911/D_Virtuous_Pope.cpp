#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<pair<int, int>> ex, ey, ez;
    auto insert = [](auto &e, int st, int ed) {
        if (st > ed) {
            swap(st, ed);
        }
        ed++;
        e.emplace_back(st, 1);
        e.emplace_back(ed, -1);
    };
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        insert(ex, x1, x2);
        insert(ey, y1, y2);
        insert(ez, z1, z2);
    }
    ranges::sort(ex);
    ranges::sort(ey);
    ranges::sort(ez);

    int ans = 0;

    int cur = 0;
    for (auto [_, i] : ex) {
        cur += i;
        ans = max(ans, cur);
    }

    cur = 0;
    for (auto [_, i] : ey) {
        cur += i;
        ans = max(ans, cur);
    }

    cur = 0;
    for (auto [_, i] : ez) {
        cur += i;
        ans = max(ans, cur);
    }

    cout << ans << "\n";

    return 0;
}