#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

auto work(vector<int> h) {
    const int n = h.size();
    auto g = h;
    for (int i = 0; i < n; i++) {
        g[i] -= i;
    }
    vector<int> stk;
    vector<i64> ans(n);

    for (int i = 0; i < n; i++) {
        while (not stk.empty() and g[stk.back()] > g[i]) {
            stk.pop_back();
        }
        if (not stk.empty() and h[i] - (i - stk.back()) >= 0) {
            int d = i - stk.back();
            ans[i] = ans[stk.back()] + 1ll * d * (h[i] + h[i] - d + 1) / 2;
        } else {
            int d = min(i + 1, h[i] + 1);
            ans[i] = 1ll * d * (h[i] + h[i] - d + 1) / 2;
        }
        stk.push_back(i);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    auto l = work(h);
    reverse(h.begin(), h.end());
    auto r = work(h);
    reverse(h.begin(), h.end());
    reverse(r.begin(), r.end());

    i64 sum = accumulate(h.begin(), h.end(), 0ll);
    i64 ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, sum - l[i] - r[i] + 2 * h[i]);
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