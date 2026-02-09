#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int B = 480;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, m;
    cin >> n >> q >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return a[i] < a[j];
    });
    vector<int> pa(n);
    for (int i = 0; i < n; i++) {
        pa[ord[i]] = i;
    }
    auto dis = [&](int i, int j) {
        if (pa[i] < pa[j]) {
            return a[j] - a[i];
        } else {
            return a[j] - a[i] + m;
        }
    };

    array<int, 3> def {0, -1, -1};
    array<int, 3> max1(def), max2(def);

    auto update = [&](int l, int r) {
        array<int, 3> cur {dis(l, r), l, r};
        if (cur > max1) {
            max2 = max1;
            max1 = cur;
        } else if (cur > max2) {
            max2 = cur;
        }
    };

    vector<int> pre(n), nxt(n);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        pre[ord[j]] = ord[i];
        nxt[ord[i]] = ord[j];

        update(ord[i], ord[j]);
    }

    const int nb = (n + B - 1) / B;
    vector<vector<array<int, 4>>> ask(nb);
    
    for (int i = 0; i < q; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        l--;
        
        ask[l / B].push_back({r, l, v, i});
    }
    for (int i = 0; i < nb; i++) {
        ranges::sort(ask[i], greater());
    }
    
    auto del = [&](int x) {
        for (int l : {pre[x], x}) {
            if (max1[1] == l) {
                max1 = def;
            }
            if (max2[1] == l) {
                max2 = def;
            }
        }
        if (max1[1] == -1) {
            swap(max1, max2);
        }
        update(pre[x], nxt[x]);
        pre[nxt[x]] = pre[x];
        nxt[pre[x]] = nxt[x];
    };
    auto rollback = [&](int x) {
        pre[nxt[x]] = x;
        nxt[pre[x]] = x;
    };

    vector<int> ans(q);
    int pl = 0;
    int pr = n;
    for (int b = 0; b < nb; b++) {
        auto exhis = array{max1, max2};
        for (auto [r, l, v, i] : ask[b]) {            
            while (pr > r) {
                del(--pr);
            }
            auto his = array{max1, max2};
            while (pl < l) {
                del(pl++);
            }

            const auto &[d1, l1, r1] = max1;
            if (pa[l1] < pa[r1]) {
                if (v <= a[l1] or v >= a[r1]) {
                    ans[i] = d1;
                } else {
                    ans[i] = max({max2[0], a[r1] - v, v - a[l1]});
                }
            } else {
                if (v <= a[l1] and v >= a[r1]) {
                    ans[i] = d1;
                } else if (v > a[l1]) {
                    ans[i] = max({max2[0], v - a[l1], a[r1] + m - v});
                } else {
                    ans[i] = max({max2[0], a[r1] - v, v + m - a[l1]});
                }
            }
            ans[i] = m - ans[i];

            while (pl > b * B) {
                rollback(--pl);
            }
            max1 = his[0];
            max2 = his[1];
        }
        while (pr < n) {
            rollback(pr++);
        }
        max1 = exhis[0];
        max2 = exhis[1];
        while (pl < min(n, (b + 1) * B)) {
            del(pl++);
        }
    }
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}