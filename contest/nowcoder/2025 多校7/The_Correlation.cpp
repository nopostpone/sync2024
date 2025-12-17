#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int odd = 0, even = 0;
    for (auto x : a) {
        if (x % 2) {
            odd++;
        } else {
            even++;
        }
    }
    int ans = (i64)odd * even % 998244353;
    cout << ans << "\n";

    return 0;
}