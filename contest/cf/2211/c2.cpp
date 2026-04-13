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

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            b[i]--;
        }
    }

    for (int i = k; i < n; i++) {
        if (a[i] != a[i - k]) {
            
        } else {

        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}