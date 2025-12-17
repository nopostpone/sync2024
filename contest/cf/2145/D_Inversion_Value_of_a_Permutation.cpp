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

    int tar = n * (n - 1) / 2 - k;

    vector<int> a;
    int len = 0;
    int sum = 0;
    bool found = false;
    [&](this auto &&self) -> void {
        if (found or sum > tar) {
            return;
        }
        if (len == n) {
            if (sum == tar) {
                found = true;
                vector<int> p;
                int x = n;
                for (auto i : a) {
                    x -= i;
                    for (int j = 0; j < i; j++) {
                        p.push_back(x + j);
                    }
                }
                for (int i = 0; i < n; i++) {
                    cout << p[i] + 1 << " \n"[i == n - 1];
                }
            }

            return;
        }
        int rest = n - len;
        if (rest * (rest - 1) / 2 + sum < tar) {
            return;
        }
        for (int i = 1; i <= n - len; i++) {
            a.push_back(i);
            len += i;
            sum += i * (i - 1) / 2;
            self();
            a.pop_back();
            len -= i;
            sum -= i * (i - 1) / 2;
        }
    } ();
    
    if (not found) {
        cout << 0 << "\n";
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