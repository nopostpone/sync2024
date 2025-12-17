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

    int a, b;
    cin >> a >> b;
    
    cout << "a = " << a << "; " << "b = " << b << endl;
    cout << "d = " << b - a << endl;

    for (int x = 0; x < (int)1e8; x++) {
        int na = a + x;
        int nb = b + x;

        cerr << nb % na << endl;

        if (nb % na != 0) {
            continue;
        }
        cout << x << " " << (b - a) / x << endl;

        // cout << "na = " << na << ", " << "nb = " << nb << endl;
    }

    return 0;
}