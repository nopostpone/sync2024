#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; ~i; i--) {
        cout << a[i].find('#') + 1 << " \n"[i == 0];
    }
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