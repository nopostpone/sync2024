#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    string s, t;
    cin >> s >> t;

    const int n = s.size();
    const int m = t.size();

    array<int, 26> fs {}, ft {};
    for (int i = 0; i < n; i++) {
        fs[s[i] - 'a']++;
    }
    for (int i = 0; i < m; i++) {
        ft[t[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (fs[i] > ft[i]) {
            cout << "Impossible\n";
            return;
        }
        ft[i] -= fs[i];
    }

    int p = 0;
    
    string ans {};
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        while (p < x) {
            while (ft[p] != 0) {
                ans += ('a' + p);
                ft[p]--;
            }
            p++;
        }
        ans += s[i];
    }
    while (p < 26) {
        while (ft[p] != 0) {
            ans += ('a' + p);
            ft[p]--;
        }
        p++;
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

    return 0;
}