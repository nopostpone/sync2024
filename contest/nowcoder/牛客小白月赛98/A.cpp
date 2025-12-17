#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;

    bool ok = false;
    while (n--) {
        int y;
        cin >> y;
        if (y == x)
            ok = 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
        
    return 0;
}