#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    // int al = 0, ar = n - 1;
    // int bl = 0, br = n - 1;

    // auto aeqb = [&]() {
    //     return (a[al] == b[bl] or a[al] == b[br]) and (a[ar] == b[bl] or a[ar] == b[br]);
    // };

    // while (al < ar and bl < br) {
    //     if (aeqb()) {
            


    //     } else {
    //         cout << "Alice\n";
    //         return;
    //     }
    // }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ok = false;
            continue;
        }
    }
    if (ok) {
        cout << "Bob\n";
        return;
    }
    ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[n - i - 1]) {
            ok = false;
            continue;
        }
    }
    if (ok) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}