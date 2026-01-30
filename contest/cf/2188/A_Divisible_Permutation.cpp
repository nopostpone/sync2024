#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    p[n - 1] = n - 1;

    if (n % 2 == 0) {
        for (int i = n - 1; i > 0; i--) {
            if (i % 2) {
                p[i - 1] = p[i] - i;
            } else {
                p[i - 1] = i + p[i];
            }
        }
    } else {
        for (int i = n - 1; i > 0; i--) {
            if (i % 2 == 0) {
                p[i - 1] = p[i] - i;
            } else {
                p[i - 1] = i + p[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n - 1];
    }
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