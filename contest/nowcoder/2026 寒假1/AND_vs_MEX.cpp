#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

vector<int> a {0};

void solve() {
    u32 l, r;
    cin >> l >> r;

    if (l == 0) {
        cout << r + 1 << "\n";
    } else if (countl_zero(l) == countl_zero(r)) {
        cout << 0 << "\n";
    } else {
        if (r >= *lower_bound(a.begin(), a.end(), l << 1)) {
            cout << r + 1 << "\n";
        } else {
            cout << r - (1 << (32 - countl_zero(l))) + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < 32; i++) {
        int v = (1ll << i) - 1;
        for (int j = 0; j < i - 1; j++) {
            a.push_back(v ^ (1 << j));
        }
    }
    ranges::sort(a);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}