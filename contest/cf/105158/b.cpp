#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    for (int i = n - 2; i >= 0; i--) {
        c[i] = min(c[i], c[i + 1]);
    }

    int ans = 0;
    for (int i = 0, cur = 0; i < n; i++) {
        cur++;
        if (cur >= c[i]) {
            cur -= c[i];
            ans++;
        }
    }
    cout << ans << "\n";
}

/*
6
3 2 5 3 4 3

5
6 3 3 4 2

5
7 6 5 9 8
*/