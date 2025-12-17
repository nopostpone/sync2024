#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

// constexpr int N = 1e6;

// int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 x;
    int n;
    cin >> x >> n;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    int q;
    cin >> q;

    vector<bool> vis(n);

    while (q--) {
        int i;
        cin >> i;
        i--;

        if (vis[i]) {
            x -= w[i];
        } else {
            x += w[i];
        }
        vis[i] = vis[i] ^ 1;
        cout << x << "\n";
    }

    return 0;
}