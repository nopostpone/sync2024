#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b /= 2, a = 1LL * a * a) {
        if (b % 2) {
            res = 1LL * res * a;
        }
    }
    return res;
}

constexpr i64 work(i64 x) {
    vector<int> dig;
    while (x) {
        dig.push_back(x % 10);
        x /= 10;
    }
    reverse(dig.begin(), dig.end());

    const int n = dig.size();
    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        if (i == n) {
            ans++;
        } else {
            ans += power(dig[0], n - 1 - i) * min(dig[0], dig[i]);
            if (dig[i] >= dig[0]) {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int mx = (i ? 9 : dig[0] - 1);
        for (int j = 1; j <= mx; j++) {
            ans += power(j, n - 1 - i);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 l, r;
    cin >> l >> r;

    cout << work(r) - work(l - 1) << "\n";

    return 0;
}