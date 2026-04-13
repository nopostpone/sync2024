#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;

        cout << min(2, n) << " \n"[i == n - 1];
    }


}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}