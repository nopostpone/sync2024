#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    int lgn = __lg(n);
    i64 m = 1ll << (lgn + 1);

    cout << m - 1 << "\n";

    return 0;
}