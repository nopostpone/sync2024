#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> r(n);
    iota(r.begin(), r.end(), 0);

    vector<int> lst(n, 0), nxt(n, n - 1);
    for (int i = 0; i < n - 1; i++) {
        lst[i + 1] = (a[i] == 0 ? i : lst[i]);
    }
    for (int i = n - 1; i; i--) {
        nxt[i - 1] = (a[i] == 0 ? i : nxt[i]);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            r[lst[i]] = max(r[lst[i]], i);
            r[i] = max(r[i], nxt[i]);
        } else if (a[i] == 2) {
            r[lst[i]] = max(r[lst[i]], nxt[i]);
        }
    }

    for (int i = 1; i < n; i++) {
        r[i] = max(r[i], r[i - 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i = r[i] + 1) {
        ans++;
    }

    cout << ans << "\n";

    return 0;
}