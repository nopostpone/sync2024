#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int P = 998244353;

constexpr int norm(int x) {
    if (x >= P) {
        x -= P;
    }
    if (x < 0) {
        x += P;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        ans[i][i] = norm(a[i] + 1);
        for (int j = i + 1; j < n; j++) {
            ans[i][j] = a[i];
            ans[j][i] = a[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
    
    return 0;
}