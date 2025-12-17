#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    bool l, r;
    cin >> l >> r;

    if ((not l and not r) or (l and r)) {
        cout << "Invalid";
    } else {
        cout << (l ? "Yes" : "No");
    }
    
    return 0;
}