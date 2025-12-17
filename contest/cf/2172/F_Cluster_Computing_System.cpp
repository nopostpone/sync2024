#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    

    vector<int> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = gcd(a[i], pre[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = gcd(suf[i + 1], a[i]);
    }

    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min(pre[i + 1], suf[i]);
    }
    cout << ans << "\n";
}