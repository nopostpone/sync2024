#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    vector s(n + 1, vector<int>(28));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 28; j++) {
            s[i][j] = s[i - 1][j] + (a[i] >> j & 1);
        }
    }

    ll res = 0;
    for (int i = 0; i <= n - 2; i++) {
        for (int j = 0; j < 28; j++) {
            if (a[i] & (1 << j)) {
                res += 1ll * (n - i - 1 - (s[n][j] - s[i + 1][j])) * (1 << j);
            } else {
                res += 1ll * (s[n][j] - s[i + 1][j]) * (1 << j);
            }
        }
    }

    cout << res << endl;

    return 0;
}