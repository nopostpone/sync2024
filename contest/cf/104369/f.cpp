#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 1e5;

unordered_map<int, int> f[4 * N];
int act[4 * N];

void modify(int p, int l, int r, int x, int c) {
    if (c > 0) {
        f[p][c]++;
    } else {
        f[p][-c]--;
    }

    if (r - l == 1) {
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        modify(2 * p, l, m, x, c);
    } else {
        modify(2 * p + 1, m, r, x, c);
    }
}
int findFirst(int p, int l, int r, int x, int y, const auto &pred) {
    if (l >= y or r <= x) {
        return -1;
    }
    if (l >= x and r <= y and not pred(p)) {
        return -1;
    }
    if (r - l == 1) {
        return l;
    }
    int m = (l + r) / 2;
    int res = findFirst(2 * p, l, m, x, y, pred);
    if (res == -1) {
        res = findFirst(2 * p + 1, m, r, x, y, pred);
    }
    return res;
}
int findLast(int p, int l, int r, int x, int y, const auto &pred) {
    if (l >= y or r <= x) {
        return -1;
    }
    if (l >= x and r <= y and not pred(p)) {
        return -1;
    }
    if (r - l == 1) {
        return l;
    }
    int m = (l + r) / 2;
    int res = findLast(2 * p + 1, m, r, x, y, pred);
    if (res == -1) {
        res = findLast(2 * p, l, m, x, y, pred);
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    [&](this auto &&self, int p, int l, int r) -> void {
        if (r - l == 1) {
            act[p] = 1;
            f[p].clear();
            f[p][c[l]] = 1;
            return;
        }
        int m = (l + r) / 2;
        self(p * 2, l, m);
        self(p * 2 + 1, m, r);

        act[p] = act[p * 2] + act[p * 2 + 1];
        f[p] = f[p * 2 + 1];
        for (const auto &[x, y] : f[p * 2]) {
            f[p][x] += y;
        }
    } (1, 0, n);

    vector<int> a(n);
    vector<i64> s(n);
    auto add = [&](int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            s[i - 1] += v;
        }
    };
    auto sum = [&](int x) {
        i64 ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += s[i - 1];
        }
        return ans;
    };

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }

    for (int i = 0; i < q; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            modify(1, 0, n, p, -c[p]);
            c[p] = x;
            modify(1, 0, n, p, c[p]);

        } else if (o == 2) {

            int p, x;
            cin >> p >> x;
            p--;
            add(p, -a[p]);
            a[p] = x;
            add(p, a[p]);

        } else {

            int x, k;
            cin >> x >> k;
            x--;

            vector<int> seq(k);
            for (int j = 0; j < k; j++) {
                cin >> seq[j];
            }
            int l = findLast(1, 0, n, 0, x, [&](int p) {
                int sum = 0;
                for (int i = 0; i < k; i++) {
                    if (f[p].contains(seq[i])) {
                        sum += f[p][seq[i]];
                    }
                }
                return sum < act[p];
            });
            int r = findFirst(1, 0, n, x + 1, n, [&](int p) {
                int sum = 0;
                for (int i = 0; i < k; i++) {
                    if (f[p].contains(seq[i])) {
                        sum += f[p][seq[i]];
                    }
                }
                return sum < act[p];
            });
            if (r == -1) {
                r = n;
            }

            cout << sum(r) - sum(l + 1) << "\n";
        }
    }
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
2
5 10
1 2 3 1 2
1 10 100 1000 10000
3 3 1 3
3 3 2 2 3
2 5 20000
2 3 200
3 3 2 1 3
3 3 3 1 2 3
1 3 4
2 1 100000
1 2 2
3 1 2 1 2
4 1
1 2 3 4
1000000 1000000 1000000 1000000
3 4 4 1 2 3 4

*/