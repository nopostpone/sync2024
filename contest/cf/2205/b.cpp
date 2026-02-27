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

    int k = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            k *= i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    k *= n;
    cout << k << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}