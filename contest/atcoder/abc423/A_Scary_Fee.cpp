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

    int x, c;
    cin >> x >> c;

    i64 ans = 1000ll * x / (1000 + c);
    ans = ans / 1000 * 1000;
    cout << ans << "\n";


    return 0;
}