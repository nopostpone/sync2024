#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, y;
    i64 x;
    cin >> n >> x >> y;

    while (n--) {
        int a, b;
        cin >> a >> b;

        if (x >= y or x < a) {
            break;
        }
        x += b - a;   
    }
    cout << x << "\n";

    return 0;
}