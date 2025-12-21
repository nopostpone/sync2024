#include <bits/stdc++.h>
using namespace std;

using p32 = pair<int, int>;

constexpr int B = 450;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, m;
    cin >> n >> q >> m;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    ranges::sort(a);

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[a[i][1]] = i;
    }

    const int nb = (n + B - 1) / B;
    vector<vector<array<int, 4>>> ask(nb);

    for (int i = 0; i < q; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        l--;
        ask[l / B].push_back({l, r, v, i});
    }

    vector<int> nxt(n), prv(n);
    for (int i = 0; i < n; i++) {
        nxt[i] = (i + 1) % n;
        prv[i] = (i + n - 1) % n;
    }

    vector<p32> e;
    auto length = [m](const p32 &a) {
        auto [l, r] = a;
        if (l > r) {
            return m + r - l;
        }
        return r - l;
    };

    p32 max1 {}, max2 {};

    auto update = [&](const p32 &cur) {
        auto len = length(cur);
        if (len >= length(max1)) {
            max2 = max1;
            max1 = cur;
        } else if (len > length(max2)) {
            max2 = cur;
        }
    };

    for (int i = 0; i < n; i++) {
        
    }

    vector<int> ans(q);

    vector<int> his;
    auto erase = [&](int i, bool flag) {
        int j = p[i];

        int l = prv[j];
        int r = nxt[j];
        nxt[l] = r;
        nxt[r] = l;

        update(pair(a[l][0], a[r][0]));

        if (flag) {
            his.push_back(j);
        }
    };
    auto rollback = [&](int t) {
        while (his.size() > t) {
            int i = his.back();
            his.pop_back();

            int l = prv[i];
            int r = nxt[i];

            nxt[l] = i;
            prv[r] = i;
        }
    };

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        update(pair(a[i][0], a[j][0]));
    }

    for (int b = 0, p = 0; b < nb; b++) {
        ranges::sort(ask[b], [](auto a, auto b) {
            return a[1] > b[1];
        });

        
    }

    for (auto x : ans) {
        cout << m - x << "\n";
    }
}

/*
4 6 7
2 0 2 5
1 4 3
2 4 6
1 3 1
1 3 5
3 4 0
3 3 2
*/