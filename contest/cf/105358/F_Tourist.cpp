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

    i64 cur = 1500;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cur += a;

        if (cur >= 4000) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << "\n";

    return 0;
}