#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    
    i64 ori = 0;
    vector<int> ans(n + 1);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        ori += a / n;
        a %= n;
        if (a + b < n) {
            ans[b]++;
            ans[a + b]--;
        } else {
            ans[b]++;
            ans[n]--;
            ans[0]++;
            ans[a + b - n]--;
        }
    }

    for (int i = 0; i < n; i++) {
        ans[i + 1] += ans[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ori + ans[i] << " \n"[i == n - 1];
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

/*
 2
 7 3
 10 0
 4 2
 21 1
 1 2
 200 0
 100 0
*/