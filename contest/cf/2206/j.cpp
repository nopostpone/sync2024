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

    int n, d;
    cin >> n >> d;

    vector<int> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        p[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        q[b[i]] = i;
    }

    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += p[b[i]] < p[b[i - 1]];
    }

    auto ans = [&]() {
        cout << i64(sum - 1) * n + p[b[n - 1]] + 1 << "\n";
    };
    ans();

    auto add = [&](int x, int y, int t) {
        x = q[x];
        y = q[y];
        if (x > y) {
            swap(x, y);
        }
        auto check = [&](int i) {
            return (i + 1 < n and p[b[i]] > p[b[i + 1]]) + (i and p[b[i - 1]] > p[b[i]]);
        };
        int res = check(x) + check(y);
        res -= (y - x == 1) and p[b[x]] > p[b[y]];
        sum += t * res;
    };

    for (int _ = 0; _ < d - 1; _++) {
        int o, x, y;
        cin >> o >> x >> y;
        x--;
        y--;

        if (o == 1) {
            add(a[x], a[y], -1);
            swap(a[x], a[y]);
            swap(p[a[x]], p[a[y]]);
            add(a[x], a[y], 1);
        } else {
            add(b[x], b[y], -1);
            swap(b[x], b[y]);
            swap(q[b[x]], q[b[y]]);
            add(b[x], b[y], 1);
        }

        ans();
    }
}