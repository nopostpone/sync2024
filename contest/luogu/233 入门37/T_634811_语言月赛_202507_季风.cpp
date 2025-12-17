#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a > 0 and b > 0) {
        cout << "NorthEast" << "\n";
    } else if (a < 0 and b < 0) {
        cout << "SouthWest" << "\n";
    } else if (a < 0 and b > 0) {
        cout << "SouthEast" << "\n";
    } else if (a > 0 and b < 0) {
        cout << "NorthWest" << "\n";
    }

    return 0;
}