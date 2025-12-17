#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    vector<i64> s(n + 2);
    for (int i = 0; i <= n; i++) {
        s[i + 1] = s[i] + pre[i];
    }

    vector<i64> f(n + 1), g(n + 1);
    for (int i = 0; i <= n; i++) {
        f[i] = pre[i] * i;
        g[i] = pre[i] * (n - i);
    }

    vector<i64> sf(n + 2), sg(n + 2);
    for (int i = 0; i <= n; i++) {
        sf[i + 1] = sf[i] + f[i];
        sg[i + 1] = sg[i] + g[i];
    }


    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;

        i64 d1 = (i64)l * (s[r + 1] - s[l + 1]);
        i64 s1 = sf[r + 1] - sf[l + 1] - d1;

        i64 d2 = i64(n - r) * (s[r] - s[l]);
        i64 s2 = sg[r] - sg[l] - d2;

        cout << s1 - s2 << "\n";
    }

    return 0;
}