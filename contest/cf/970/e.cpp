#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = n;

    vector cnt(2, vector<int>(26));
    for (int i = 0; i < n; i++) {
        cnt[i & 1][s[i] - 'a']++;
    }
    if (n % 2 == 0) {
        ans = n - *max_element(cnt[0].begin(), cnt[0].end()) - *max_element(cnt[1].begin(), cnt[1].end());
    } else {
        for (int i = n - 1; ~i; i--) {
            cnt[i & 1][s[i] - 'a']--;

            int t = n - *max_element(cnt[0].begin(), cnt[0].end()) - *max_element(cnt[1].begin(), cnt[1].end());
            ans = min(ans, t);

            cnt[(i + 1) & 1][s[i] - 'a']++;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}