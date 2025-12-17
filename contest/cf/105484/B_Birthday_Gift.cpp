#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    string s;
    cin >> s;

    const int n = s.size();

    int cnt[2]{};
    int c2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '2') {
            int bel = (s[i] - '0') ^ (i % 2);
            cnt[bel]++;
        } else {
            c2++;
        }
    }
    int u = min(cnt[0], cnt[1]);
    int v = max(cnt[0], cnt[1]);
    if (v - u >= c2) {
        u += c2;
    } else {
        c2 -= v - u;

        u = v;
        u += c2 / 2;
        v += c2 - c2 / 2;
    }

    cout << n - min(u, v) * 2 << "\n";
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