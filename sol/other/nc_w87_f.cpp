// https://ac.nowcoder.com/acm/contest/73854/E
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> prexor(n);
    for (int i = 0; i < n - 1; i++) {
        prexor[i + 1] = prexor[i] ^ a[i];
    }

    ll res = -4e18; 
    int x = 0;    
    for (int i = n - 1; i > 1; i--) {
        x |= a[i - 1];
        res = max<ll>(res, 1ll * prexor[i - 1] + x);
    }
    cout << res + a[n - 1];

    return 0;
}