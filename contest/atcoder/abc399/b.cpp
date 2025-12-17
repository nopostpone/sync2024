#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
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
    auto b = a;
    ranges::sort(b);
    for (int i = 0; i < n; i++) {
        int ans = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans = n - ans;
        cout << ans + 1 << "\n";
    }


    return 0;
}