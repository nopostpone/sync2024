#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (ranges::count(b, b[0]) == n) {
        cout << k << " " << i64(k) * (k + 1) / 2 << "\n";
        return;
    }
    
    vector<int> lc(n, -1), rc(n, -1);
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (not stk.empty() and b[i] < b[stk.back()]) {
            int x = stk.back();
            stk.pop_back();

            rc[x] = lc[i];
            lc[i] = x;
        }
        stk.push_back(i);
    }
    while (stk.size() > 1) {
        int x = stk.back();
        stk.pop_back();
        rc[stk.back()] = x;
    }

    int s = INT_MAX;
    int base = 0;
    for (int i = 0; i < n - 1; i++) {
        if (b[i + 1] == b[i]) {
            continue;
        }
        if (int ns = std::abs(b[i + 1] - b[i]); ns < s) {
            s = ns;
            base = min(b[i + 1], b[i]);
        }
    }

    int cnt = 0;
    i64 sum = 0;

    auto check = [&](int x) {
        if (x <= 0 or x > k) {
            return;
        }
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (lc[i] != -1 and (b[lc[i]] + x) % (b[i] + x)) {
                valid = false;
            }
            if (rc[i] != -1 and (b[rc[i]] + x) % (b[i] + x)) {
                valid = false;
            }
        }
        if (valid) {
            cnt++;
            sum += x;
        }
    };
    for (int d = 1; d * d <= s; d++) {
        if (s % d == 0) {
            check(d - base);
            if (d != s / d) {
                check(s / d - base);
            }
        }
    }

    cout << cnt << " " << sum << "\n";
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