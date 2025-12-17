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

    vector<bool> f(k);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        f[x] = true;
    }

    int ori = 0;

    vector<int> cnt(k);
    map<pair<int, int>, int> todo;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (f[a] and f[b]) {
            ori++;
        } else if (f[a]) {
            cnt[b]++;
        } else if (f[b]) {
            cnt[a]++;
        } else {
            if (a == b) {
                cnt[a]++;
            } else {
                todo[minmax(a, b)]++;
            }
        }
    }

    int ans = ori;

    for (auto [pr, c] : todo) {
        auto [x, y] = pr;
        ans = max(ans, ori + cnt[x] + cnt[y] + c);
    }
    ranges::sort(cnt, greater());

    if (cnt.size() >= 2) {
        ans = max(ans, ori + cnt[0] + cnt[1]);
    } else {
        ans = max(ans, ori + cnt[0]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}