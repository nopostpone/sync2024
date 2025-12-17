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

    if (n == 2) {
        cout << "No";
        return 0;
    }
    if (std::gcd<i64>(n, n - 2) == 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}