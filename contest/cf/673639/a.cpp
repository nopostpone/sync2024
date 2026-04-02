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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> p(k + 1);
    for (int i = 1; i <= k; i++) {
        p[a[i]] = n - i + 1;
    }

    vector<int> dp(k + 1);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
        }
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
}