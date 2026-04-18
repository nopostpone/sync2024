#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans >= a[i]) {
            ans++;
        } else {
            ans--;
        }
    }
    cout << ans << " ";

    ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (ans >= a[i]) {
            ans++;
        } else {
            ans--;
        }
    }
    cout << ans << "\n";
}