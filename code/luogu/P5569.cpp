#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    ll res = 0;
    while (a.size() > 1) {
        int k = a.size() - 1;
        for (int i = 1; i < a.size() - 1; i++) {
            if (a[i + 1] > a[i - 1]) {
                k = i;
                break;
            }
        }
        int j = 0;
        for (int i = k - 1; ~i; i--) {
            if (a[i - 1] > a[k - 1] + a[k]) {
                j = i;
                break;
            }
        }
        ll t = a[k - 1] + a[k];
        res += t;
        a.erase(a.begin() + k - 1);
        a.erase(a.begin() + k - 1);
        a.insert(a.begin() + j, t);
    }

    cout << res;

    return 0;
}