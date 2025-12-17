#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    if (n == 1) {
        cout << (a == b) << "\n";
        cout << a << ":" << b << "\n";
        return 0;
    }

    if (a + b <= n) {
        cout << n - a - b << "\n";
        for (int i = 0; i < a; i++) {
            cout << "1:0\n";
        }
        for (int i = 0; i < b; i++) {
            cout << "0:1\n";
        }
        for (int i = 0; i < n - a - b; i++) {
            cout << "0:0\n";
        }
    } else {
        cout << 0 << "\n";
        for (int i = 0; i < n - (a != 0) - (b != 0); i++) {
            if (a > 1) {
                cout << "1:0\n";
                a--;
            } else if (b > 1) {
                cout << "0:1\n";
                b--;
            } else {
                break;
            }
        }
        if (a) {
            cout << a << ":0\n";
        }
        if (b) {
            cout << "0:" << b << "\n";
        }
    }
    
    

    return 0;
}