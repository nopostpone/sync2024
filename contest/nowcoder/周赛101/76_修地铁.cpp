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

    int a{}, b{}, c{}, d{};
    for (int i = 1; i <= n; i++) {
        if (i % 5 == 0) {
            a += 2;
        }
        if (i % 10 == 5) {
            b++;
        }
        if (i % 20 == 0) {
            c += 3;
        } else {
            d += 2;
        }
    }
    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}