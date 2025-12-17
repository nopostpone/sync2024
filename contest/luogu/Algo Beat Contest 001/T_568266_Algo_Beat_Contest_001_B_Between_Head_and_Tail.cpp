#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int l, r;
    cin >> l >> r;
    r++;
    for (int x = l; x < r; x++) {
        int now = x;
        vector<int> a;
        while (now) {
            a.push_back(now % 10);
            now /= 10;
        }
        if (a.size() % 2) {
            int u = a.front();
            int v = a.back();
            int w = *(a.begin() + a.size() / 2);
            if (u == v and v == w) {
                cout << x << " ";
            }
        }
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}