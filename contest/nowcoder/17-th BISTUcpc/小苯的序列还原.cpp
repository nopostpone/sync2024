#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n);
    int cur = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        p[cur++] = i;
    }
    for (int i = (p[cur - 1] == 0); i < n; i += 2) {
        p[cur++] = i;
    }

    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        q[p[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << a[q[i]] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}