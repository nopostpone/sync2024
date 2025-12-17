#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    array<int, 64> f{};
    for (auto x : a) {
        for (int i = 60; i >= 0; i--) {
            if (x >> i & 1) {
                f[i]++;
            }
        }
    }
    bool ok = true;
    for (auto x : a) {
        for (int i = 60; i >= 0; i--) {
            if (x >> i & 1) {
                if (f[i] > 1) {
                    ok = false;
                }
                break;
            }
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}