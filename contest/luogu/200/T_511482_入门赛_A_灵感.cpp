#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    bool ok = a[3] + a[2] > a[0] + a[1];
    cout << (ok ? "Yes" : "No");
    
    return 0;
}