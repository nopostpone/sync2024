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
    i64 ans = 0;


    map<int, int> cnt;
    for (int i = n - 1; i >= 0; i--) {
        ans += cnt[a[i] + i];
        cnt[i - a[i]]++;
    }
    cout << ans << "\n";

    return 0;
}