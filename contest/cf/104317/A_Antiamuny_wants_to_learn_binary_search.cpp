#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int f(int l, int r, int x) { // l <= x <= r
    int cnt = 0;
    while (l <= r) {
        cnt++;
        int mid = (l + r) / 2;
        if (mid == x)
            break;
        if (mid < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int l, r, x;
        cin >> l >> r >> x;

        cout << f(l, r, x) << "\n";
    }

    return 0;
}