// https://ac.nowcoder.com/acm/contest/73854/E
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<ll> a(n), premx(n, -4e18);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        premx[i + 1] = max(premx[i], a[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << max<ll>(premx[i + 1] - a[i], 0) << " ";
    }

    return 0;
}