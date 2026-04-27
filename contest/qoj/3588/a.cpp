#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int N = 1e7;

vector<pair<int, int>> bounds;

void solve() {
    int n;
    cin >> n;

    for (auto [l, r] : bounds) {
        if (n < l or n > r) {
            continue;
        }

        int t = n / (int)'a';
        string ans(t, 'a');

        n -= t * (int)'a';

        for (int i = 0; i < t and n; i++) {
            int x = min(n, 25);
            n -= x;
            ans[i] += x;
        }

        cout << "Yes\n" << ans << "\n";
        return;
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1, l, r = 0; r < N; i++) {
        l = (int)'a' * i;
        r = (int)'z' * i;
        if (r > (int)'a' * (i + 1)) {
            r = N;
        }
        bounds.emplace_back(l, r);
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}