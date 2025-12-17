#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    string s;
    cin >> s;

    vector<array<int, 3>> que(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y++;
        que[i] = {x, y, i};
    }
    const int sqrtn = sqrt(n);
    ranges::sort(que, [&](auto i, auto j) {
        if (i[0] / sqrtn != j[0] / sqrtn) {
            return i[0] < j[0];
        }
        return (i[0] / sqrtn) % 2 ? i[1] > j[1] : i[1] < j[1];
    });


    vector<array<int, 26>> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i];
        f[i + 1][s[i] - 'a']++;
        f[i + 1][s[i] - 'a'] %= k;
    }
    map<array<int, 26>, int> vis;
    vector<int> g(n + 1);
    for (int i = 0, cur = 0; i <= n; i++) {
        if (not vis.contains(f[i])) {
            vis[f[i]] = cur++;
        }
        g[i] = vis[f[i]];
    }

    i64 res = 0;

    vector<int> cnt(ranges::max(g) + 1);
    auto add = [&](int p) {
        res += cnt[g[p]];
        cnt[g[p]]++;
    };
    auto del = [&](int p) {
        cnt[g[p]]--;
        res -= cnt[g[p]];
    };

    int L = 0, R = 0;
    vector<i64> ans(q);
    for (auto [l, r, i] : que) {
        while (L > l) {
            add(--L);
        }
        while (R < r) {
            add(R++);
        }
        while (L < l) {
            del(L++);
        }
        while (R > r) {
            del(--R);
        }
        ans[i] = res;
    }
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}