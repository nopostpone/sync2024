#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y;
    cin >> y;

    int ny = y;

    int x = 0;
    while (ny) {
        x += ny % 10;
        ny /= 10;
    }

    constexpr auto check = [](int x) {
        int sqrtx = sqrt(x);
        while (sqrtx * sqrtx > x) {
            sqrtx--;
        }
        return sqrtx * sqrtx == x;
    };

    cout << (check(x) and check(y) ? "Yes" : "No") << "\n";    

    return 0;
}