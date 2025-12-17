#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> s;

    vector<int> ans(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        now += a[i];
        int t = now;
        for (auto it = s.rbegin(); it != s.rend() and t > m; it++) {
            ans[i]++;
            t -= *it;
        }
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}