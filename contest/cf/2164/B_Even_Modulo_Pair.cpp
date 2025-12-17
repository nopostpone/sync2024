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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    {
        vector<int> even;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
            }
        }
        if (even.size() >= 2) {
            cout << even[0] << " " << even[1] << "\n";
            return;
        }
        if (not even.empty()) {
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 0) {
                    break;
                }
                if ((even[0] % a[i]) % 2 == 0) {
                    cout << a[i] << " " << even[0] << "\n";
                    return;
                }
            }
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[j] % a[i]) % 2 == 0) {
                cout << a[i] << " " << a[j] << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // vector a = {3, 7, 10, 19};

    // for (int i = 8; i <= 1000; i++) {
    //     bool ok = true;
    //     for (auto x : a) {
    //         if (i % x % 2 == 0) {
    //             ok = false;
    //         }
    //     }
    //     if (ok) {
    //         cout << i << endl;
    //     }
    // }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}