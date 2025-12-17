#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i + k <= n; i++) {
        auto na = a;
        for (int j = 0; j < k; j++) {
            na[i + j] -= 2;
        }
        int win = 0;
        for (int j = 0; j < n; j++) {
            win += (na[j] < 50);
        }

        ans += (win > (n - 1) / 2);
    }
    cout << ans << "\n";

    return 0;
}