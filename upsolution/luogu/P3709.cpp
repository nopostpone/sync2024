#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int B = 450;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto v = a;
    ranges::sort(v);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &x : a) {
        x = ranges::lower_bound(v, x) - v.begin();
    }
    int V = v.size();

    vector<array<int, 3>> que(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;

        que[i] = {l, r, i};
    }
    ranges::sort(que, [&](auto x, auto y) {
        int b1 = x[0] / B;
        int b2 = y[0] / B;
        if (b1 != b2) {
            return b1 < b2;
        }
        if (b1 % 2) {
            return x[1] > y[1];
        }
        return x[1] < y[1];
    });

    vector<int> cnt(V, 0), freq(n + 1);
    freq[0] = V;
    int L = 0, R = 0, cur = 0;

    auto add = [&](int p) {
        int v = a[p];
        int c = cnt[v];
        cnt[v]++;
        freq[c]--;
        freq[c + 1]++;

        cur = max(c + 1, cur);
    };
    auto remove = [&](int p) {
        int v = a[p];
        int c = cnt[v];
        cnt[v]--;
        freq[c]--;
        freq[c - 1]++;

        while (freq[cur] == 0) {
            cur--;
        }
    };

    vector<int> ans(q);
    for (auto [l, r, id] : que) {
        while (L > l) {
            L--;
            add(L);
        }
        while (R < r) {
            add(R);
            R++;
        }
        while (L < l) {
            remove(L);
            L++;
        }
        while (R > r) {
            R--;
            remove(R);
        }
        ans[id] = -cur;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
