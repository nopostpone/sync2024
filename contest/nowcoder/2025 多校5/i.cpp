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

    if (n % 2 == 0) {
        cout << (n + 1 + n / 2) * 2 << "\n";
    } else {
        cout << ((n + 1) / 2 + n) * 2 << "\n";
    }

    return 0;
}