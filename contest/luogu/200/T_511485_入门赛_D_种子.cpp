#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int x, y, w, k;
    cin >> x >> y >> w >> k;

    int now = 0;
    for (int i = 0; i < 1e9; i++) {
        now += i / w;
        if (i >= x) {
            now += y;
        }
        if (now >= k) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}