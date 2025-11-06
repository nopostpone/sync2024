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

    int q;
    cin >> q;

    multiset<int> s;
    multiset<tuple<int, int, int>> cur;

    for (int _ = 0; _ < q; _++) {
        int o;
        cin >> o;

        if (o == 1) {
            int x;
            cin >> x;

            auto r = s.lower_bound(x);
            if (r != s.end() and r != s.begin()) {
                auto l = prev(r);
                int u = *l;
                int v = *r;
                int t = u ^ v;
                cur.extract(tuple(t, u, v));
            }

            if (r != s.end()) {
                int v = *r;
                cur.insert(tuple(x ^ v, x, v));
            }
            if (r != s.begin()) {
                int u = *prev(r);
                cur.insert(tuple(u ^ x, u, x));
            }

            s.insert(x);
        } else if (o == 2) {
            int x;
            cin >> x;

            s.extract(x);
            auto r = s.lower_bound(x);
            if (r != s.end()) {
                int v = *r;
                cur.extract(tuple(x ^ v, x, v));
            }
            if (r != s.begin()) {
                int u = *prev(r);
                cur.extract(tuple(u ^ x, u, x));
            }
            if (r != s.end() and r != s.begin()) {
                auto l = prev(r);
                int u = *l;
                int v = *r;
                int t = u ^ v;
                cur.insert(tuple(t, u, v));
            }

        } else {
            auto [ans, x, y] = *cur.begin();
            cout << ans << "\n";
        }
    }

    return 0;
}