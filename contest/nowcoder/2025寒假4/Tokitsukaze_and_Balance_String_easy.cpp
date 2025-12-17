#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            a.push_back(i);
        }
    }
    const int m = a.size();

    auto work = [&](int t) {
        for (int i = 0; i < m; i++) {
            if ((t >> i) & 1) {
                s[a[i]] = '1';
            } else {
                s[a[i]] = '0';
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            s[i] ^= 1;
            int u{};
            for (int j = 1; j < n; j++) {
                if (s[j - 1] == '1' and s[j] == '0') {
                    u++;
                }
                if (s[j - 1] == '0' and s[j] == '1') {
                    u--;
                }
            }
            ans += (u == 0);
            s[i] ^= 1;
        }
        return ans;
    };
    
    i64 ans = 0;
    for (i64 i = 0; i < (1ll << m); i++) {
        ans += work(i);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}