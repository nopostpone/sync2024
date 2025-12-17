#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        a[i]--;
    }

    bool ok = true;
    for (int i = 0; i < 2 * n; i++) {e
        if (a[i] == i) {
            ok = false;
        }
        if (a[a[i]] != i) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}