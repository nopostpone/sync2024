#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<int> type(n);
    for (int i = 0; i < n; i++) {
        if (l[i] == r[i]) {
            type[i] = 1;
        } else if (l[i] + 1 == r[i]) {
            type[i] = 2;
        } else {
            type[i] = 3;
        }
    }

    vector<array<int, 2>> e;
    for (int i = 0; i < n; i++) {
        if (type[i] != 0) {
            if (e.empty() or // no segments
                e.back()[1] != i or // previous segment is not adjacent
                type[e.back()[0]] != type[i] or // previous segment's type different
                (i > 0 and (l[i] > r[i - 1] or l[i - 1] > r[i]))) { // no intersect

                    e.push_back({i, i + 1});
            } else {
                e.back()[1] = i + 1;
            }
        } else {
            e.push_back({i, i + 1});
        }
    }

    i64 ans = 0;
    for (int i = 0; i < e.size(); i++) {
        auto [x, y] = e[i];
        auto len = y - x;

        if (type[x] == 1) {
            ans += 1ll * len * len;
        } else if (type[x] == 3) {
            ans += len;
        } else {

            if ((i == 0 or type[e[i - 1][0]] != 1) or 
                (i + 1 >= e.size() or type[e[i + 1][0]] != 1)) {
                    ans += len;
            } else {
                bool out = false;
                
                int cur = l[x - 1];
                for (int i = x; i <= y; i++) {
                    if (cur != l[i] and cur != r[i]) {
                        out = true;
                        break;
                    } else if (cur == l[i]) {
                        cur = r[i];
                    } else {
                        cur = l[i];
                    }
                }

                if (not out and cur == l[y]) {
                    if (len == 1) {
                        int l1 = e[i - 1][1] - e[i - 1][0];
                        int l2 = e[i + 1][1] - e[i + 1][0];

                        if (l1 <= l2) {
                            ans += 2 * l1 + 1;
                        } else {
                            e[i + 1][0]--;
                            l[x] = l[y];
                            r[x] = r[y];
                            type[x] = 1;
                        }
                    } else {
                        ans += len + 2;
                    }
                } else {
                    ans += len;
                }
            }
        }
    }

    cout << ans << "\n";
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
3
3
1 1 4
5 1 4
6
1 2 3 4 4 4
3 3 3 4 5 6
7
1 1 2 2 1 1 1
1 2 2 2 2 1 1
*/
