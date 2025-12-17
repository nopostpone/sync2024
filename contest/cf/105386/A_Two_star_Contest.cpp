#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> s(n), cnt(n);
    vector a(n, vector<int>(m));
    vector<i64> sum(n);

    map<int, i64> lo, hi;

    vector<int> todo;

    for (int i = 0; i < n; i++) {
        cin >> s[i];

        bool cert = true;

        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                cert = false;
                cnt[i]++;
            } else {
                sum[i] += a[i][j];
            }
        }
        if (cert) {
            if (lo.contains(s[i])) {
                lo[s[i]] = min(lo[s[i]], sum[i]);
                hi[s[i]] = max(hi[s[i]], sum[i]);
            } else {
                lo[s[i]] = sum[i];
                hi[s[i]] = sum[i];
            }
        } else {
            todo.push_back(i);
        }
    }

    {
        int lst = -1;
        bool valid = true;
        for (auto [lvl, val] : lo) {
            if (lst != -1) {
                if (val <= hi[lst]) {
                    valid = false;
                }
            }
            lst = lvl;
        }

        if (not valid) {
            cout << "No\n";
            return;
        }
    }
    ranges::sort(todo, [&](int i, int j) {
        return s[i] < s[j];
    });

    for (auto i : todo) {
        {
            auto it = hi.lower_bound(s[i]);
            if (it != hi.begin()) {
                auto nlo = prev(it)->second + 1;

                if (sum[i] + (i64)k * cnt[i] < nlo) {
                    cout << "No\n";
                    return;
                } else {
                    auto d = nlo - sum[i];
                    int j = 0;
                    for (; j < m and d > 0; j++) {
                        if (a[i][j] != -1) {
                            continue;
                        }
                        if (d > k) {
                            a[i][j] = k;
                            d -= k;
                        } else {
                            a[i][j] = d;
                            break;
                        }
                    }
                    for (; j < m; j++) {
                        if (a[i][j] == -1) {
                            a[i][j] = 0;
                        }
                    }
                }
            } else {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == -1) {
                        a[i][j] = 0;
                    }
                }
            }
        }
        sum[i] = accumulate(a[i].begin(), a[i].end(), i64());
        {
            auto it = lo.upper_bound(s[i]);
            if (it != lo.end()) {
                if (sum[i] >= it->second) {
                    cout << "No\n";
                    return;
                }
            }
        }


        if (lo.contains(s[i])) {
            lo[s[i]] = min(lo[s[i]], sum[i]);
            hi[s[i]] = max(hi[s[i]], sum[i]);
        } else {
            lo[s[i]] = sum[i];
            hi[s[i]] = sum[i];
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m - 1];
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

    return 0;
}