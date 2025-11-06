// https://ac.nowcoder.com/acm/contest/20960/1014
// 双指针模板题
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = a;
    ranges::sort(b);
    for (auto &x : a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin();
    }

    vector<vector<pair<int, int>>> ans(n);
    int len = 0;

    vector<bool> exi(n);
    for (int i = 1, j = 0; i <= n; i++) {
        while (exi[a[i - 1]]) {
            exi[a[j]] = false;
            j++;
        }
        exi[a[i - 1]] = true;
        ans[i - j].push_back(make_pair(j + 1, i));
        len = max(len, i - j);
    }

    cout << ans[len].size() << "\n";
    for (auto [x, y] : ans[len]) {
        cout << x << " " << y << "\n";
    }

    return 0;
}