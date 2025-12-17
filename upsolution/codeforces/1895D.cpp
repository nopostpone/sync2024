#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        a[i + 1] = a[i] ^ x;
    }
    
    int st{};
    for (int i = 0; i < 31; i++) {
        int s{};
        for (int j = 0; j < n; j++) {
            if (a[j] >> i & 1) {
                s++;
            }
        }
        if (s > n - s) {
            st |= (1 << i);
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] ^= st;
        cout << a[i] << " ";
    }
    
    return 0;
}