#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    map<int, int> f;
    multiset<int> s;
    
    for (int i = 0; i < n; i++) {
        s.insert(0);
    }
    for (int i = 0; i < k - 1; i++) {
        s.extract(f[a[i] - i]);
        f[a[i] - i]++;
        s.insert(f[a[i] - i]);
    }
    
    vector<int> ans(n);
    for (int i = k - 1; i < n; i++) {
        s.extract(f[a[i] - i]);
        f[a[i] - i]++;
        s.insert(f[a[i] - i]);
        
        int p = i - k + 1;
        ans[p] = k - *s.rbegin();
        s.extract(f[a[p] - p]);
        f[a[p] - p]--;
        s.insert(f[a[p] - p]);
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ans[l - 1] << endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}