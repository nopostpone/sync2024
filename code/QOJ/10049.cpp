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

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    unordered_map<int, i64> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (i) {
            cnt[b[i]]++;
        }
    }

    for (int i = 2; i < n; i++) {
        a[i] = max(a[i], a[i - 1]);
        b[i] = max(b[i], b[i - 1]);
    }

    vector<int> f(n + 1);
    for (int i = 1; i < n; i++) {
        int p = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        f[p]++;
        cnt[b[i]] += max(0, p - 1);
    }
    for (int i = 1; i < n; i++) {
        f[i] += f[i - 1];
        cnt[a[i]] += f[i];
    }

    auto ans = pair(i64(), -1);
    for (auto [x, y] : cnt) {
        ans = max(ans, pair(y, x));
    }
    cout << ans.second << " " << ans.first << "\n";

    return 0;
}

/*
3
5 2 5
5 3 1

3
1 7 8
1 3 5

4
2 1 2 1
2 1 1 2
*/