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

    int n, k;
    cin >> n >> k;

    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    int mn = ranges::min(c);

    vector<tuple<int, string, int>> info(n);
    int tot = 0;
    for (auto &[w, s, i] : info) {
        cin >> w >> s;
        i = tot++;
    }
    ranges::sort(info, greater());

    map<string, int> cnt;
    vector<int> ans(n);

    int rk = 0;
    for (auto [w, s, i] : info) {
        // cerr << w << " " << s << " " << min(cnt[s], mn) << endl;
        if (cnt[s] >= mn) {
            ans[i]--;
        }
        ans[i] += rk + 1;
        if (cnt[s] < mn) {
            rk++;
        }
        cnt[s]++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}