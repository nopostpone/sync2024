#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 2e9;

constexpr int N = 5e5;
int a[N];

int n;

struct Node {
    i64 sum = {};
    int act = {};
    int maxa = {};
    int cnt = {};
    int se = {};
    int maxb = {};

    array<int, 4> add = {};

    Node() {}
    void apply(array<int, 4> t) {
        sum += 1ll * t[0] * cnt;
        sum += 1ll * t[1] * (act - cnt);

        maxb = max(maxb, maxa + t[2]);
        maxa += t[0];

        if (se != -inf) {
            se += t[1];
        }

        add[2] = max(add[2], add[0] + t[2]);
        add[3] = max(add[3], add[1] + t[3]);
        add[0] += t[0];
        add[1] += t[1];
    }
} s[4 << __lg(N)];

Node merge(const Node &a, const Node &b) {
    Node c;
    c.act = a.act + b.act;
    c.sum = a.sum + b.sum;
    c.maxa = max(a.maxa, b.maxa);
    c.maxb = max(a.maxb, b.maxb);
    if (a.maxa == b.maxa) {
        c.se = max(a.se, b.se);
        c.cnt = a.cnt + b.cnt;
    } else if (a.maxa > b.maxa) {
        c.se = max(a.se, b.maxa);
        c.cnt = a.cnt;
    } else {
        c.se = max(a.maxa, b.se);
        c.cnt = b.cnt;
    }
    return c;
}

void pull(int p) {
    s[p] = merge(s[p * 2], s[p * 2 + 1]);
}
void push(int p) {
    int tem = max(s[p * 2].maxa, s[p * 2 + 1].maxa);
    if (s[p * 2].maxa == tem) {
        s[p * 2].apply(s[p].add);
    } else {
        s[p * 2].apply(array{s[p].add[1], s[p].add[1], s[p].add[3], s[p].add[3]});
    }

    if (s[p * 2 + 1].maxa == tem) {
        s[p * 2 + 1].apply(s[p].add);
    } else {
        s[p * 2 + 1].apply(array{s[p].add[1], s[p].add[1], s[p].add[3], s[p].add[3]});
    }

    s[p].add = {};
}

void build(int p, int l, int r) {
    if (r - l == 1) {
        s[p].sum = s[p].maxa = s[p].maxb = a[l];
        s[p].cnt = 1;
        s[p].act = 1;
        s[p].se = -inf;
        s[p].add = {};
        return;
    }
    int m = (l + r) / 2;
    build(p * 2, l, m);
    build(p * 2 + 1, m, r);
    pull(p);
}

constexpr int def[] = {0, -inf};
i64 rangeQuery(int p, int l, int r, int x, int y, int type) {
    if (l >= y or r <= x) {
        return def[type != 0];
    }
    if (l >= x and r <= y) {
        if (type == 0) {
            return s[p].sum;
        } else if (type == 1) {
            return s[p].maxa;
        } else {
            return s[p].maxb;
        }
    }
    push(p);
    int m = (l + r) / 2;
    if (type) {
        return max(rangeQuery(p * 2, l, m, x, y, type), rangeQuery(p * 2 + 1, m, r, x, y, type));
    } else {
        return rangeQuery(p * 2, l, m, x, y, type) + rangeQuery(p * 2 + 1, m, r, x, y, type);
    }
}
void rangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y or r <= x) {
        return;
    }
    if (l >= x and r <= y) {
        s[p].sum += 1ll * v * (r - l);
        s[p].maxa += v;
        s[p].maxb = max(s[p].maxa, s[p].maxb);
        if (s[p].se != -inf) {
            s[p].se += v;
        }

        s[p].add[0] += v;
        s[p].add[1] += v;
        s[p].add[2] = max(s[p].add[2], s[p].add[0]);
        s[p].add[3] = max(s[p].add[3], s[p].add[1]);

        return;
    }
    push(p);
    int m = (l + r) / 2;
    rangeAdd(p * 2, l, m, x, y, v);
    rangeAdd(p * 2 + 1, m, r, x, y, v);
    pull(p);
}
void rangeMin(int p, int l, int r, int x, int y, int v) {
    if (l >= y or r <= x or v >= s[p].maxa) {
        return;
    }
    if (l >= x and r <= y and s[p].se < v) {
        int k = s[p].maxa - v;
        s[p].sum -= 1ll * s[p].cnt * k;
        s[p].maxa = v;

        s[p].add[0] -= k;
        return;
    }
    push(p);
    int m = (l + r) / 2;
    rangeMin(p * 2, l, m, x, y, v);
    rangeMin(p * 2 + 1, m, r, x, y, v);
    pull(p);
}

i64 rangeQuery(int x, int y, int type) {
    return rangeQuery(1, 0, n, x, y, type);
}
void rangeAdd(int x, int y, int v) {
    rangeAdd(1, 0, n, x, y, v);
}
void rangeMin(int x, int y, int v) {
    rangeMin(1, 0, n, x, y, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n);

    for (int i = 0; i < m; i++) {
        int o, x, y;
        cin >> o >> x >> y;
        x--;

        switch (o) {
        case 1:
            int k;
            cin >> k;
            rangeAdd(x, y, k);
            break;
        case 2:
            int v;
            cin >> v;
            rangeMin(x, y, v);
            break;
        default:
            cout << rangeQuery(x, y, o - 3) << "\n";
            break;
        }
    }

    return 0;
}