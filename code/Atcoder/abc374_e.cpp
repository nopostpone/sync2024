#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        int A, P, B, Q;
        cin >> A >> P >> B >> Q;
        a[i] = make_pair(A, P);
        b[i] = make_pair(B, Q);
    }

    

    return 0;
}