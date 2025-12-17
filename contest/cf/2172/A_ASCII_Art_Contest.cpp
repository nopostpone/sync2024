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

    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    if (a[2] - a[0] >= 10) {
        cout << "check again\n";
    } else {
        cout << "final " << a[1] << "\n";
    }

    return 0;
}