#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, a, b;
    cin >> n >> a >> b;

    i128 ans = b;
    ans = min(ans, (i128)n * a);

    cout << (i64)ans << "\n";

    return 0;
}