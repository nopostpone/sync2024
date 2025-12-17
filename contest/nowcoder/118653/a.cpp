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

    i64 a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    cout << min(a, y) + min(b, z) + min(c, x) << endl;

    return 0;
}