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

    int n, m;
    cin >> n >> m;

    int g = (n + 9) / 10;
    if (m <= g) {
        cout << "Gold";
    } else if (m <= 3 * g) {
        cout << "Silver";
    } else if (m <= 6 * g) {
        cout << "Bronze";
    } else {
        cout << "Pig";
    }
}