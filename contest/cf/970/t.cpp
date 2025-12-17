#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("1.out", "w", stdout);
    
    cout << 9999 << endl;
    int cur = 0;
    for (int i = 0; i < 9999; i++, cur++) {
        cout << fixed << 1 + (cur & 1) << " " << int(1e9 - cur) << endl;
    }
    
    return 0;
}