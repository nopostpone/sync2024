#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;



int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }



    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 3) {
            int l, r;
            cin >> l >> r;
            l--, r--;
        } else {
            int i, x;
            cin >> i >> x;
            i--;
        }
    }
    
    return 0;
}