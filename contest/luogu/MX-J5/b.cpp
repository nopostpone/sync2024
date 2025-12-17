#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int in = *max_element(a.begin(), a.end());
    int out = 0;
    for (int i = 0; i < n; i++) {
        out += a[i] != 0;
    }
    cout << in + out << endl;
    
    return 0;
}