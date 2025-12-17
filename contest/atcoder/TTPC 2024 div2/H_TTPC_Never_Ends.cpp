#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    array<int, 4> x;
    for (int i = 0; i < 4; i++) {
        cin >> x[i];
    }

    vector f(n, vector<int>(20));
    for (int i = 0; i < n; i++) {
        f[i][0] = a[i];
    }
    for (int i = 1; i < 20; i++) {
        
    }
    
    return 0;
}