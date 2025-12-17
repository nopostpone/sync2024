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

    vector<int> a(n);
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

        vec[a[i]].push_back(i);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (i and a[i] == a[i - 1]) {
            continue;
        }
        int p = lower_bound(vec[a[i]].begin(), vec[a[i]].end(), i) - vec[a[i]].begin();
        ans += n - i - (vec[a[i]].size() - p);

    }
    ans++;
    cout << ans << "\n";

    return 0;
}