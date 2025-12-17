#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int A = 0, B = 0;
    bool isA = 1;
    for (int i = n - 1; ~i; i--) {
        if (isA) {
            A += a[i];
        } else {
            B += a[i];
        }
        isA ^= 1;
    }

    cout << (A > B ? "Alice" : "Bob") << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}