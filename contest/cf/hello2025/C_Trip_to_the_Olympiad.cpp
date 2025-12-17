#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int n = 30;

void solve() {
    int l, r;
    cin >> l >> r;

    deque<int> b;
    int ans{};
    bool g{};
    for (int i = n - 1; ~i; i--) {
        int L = ((l >> i) & 1);
        int R = ((r >> i) & 1);
        if (L == R) {
            if (g) {
                ans += ((L xor 1) << i);
            } else {
                ans += (L << i);
            }
        } else {
            g = true;
            b.push_back(1 << i);
        }
    }
    while (ans <= l and not b.empty()) {
        while (not b.empty() and ans + b.front() >= r) {
            b.pop_front();
        }
        if (not b.empty()) {
            ans += b.front();
        }
    }
    cout << l << " " << ans << " " << r << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}