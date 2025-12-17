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

    int n, r;
    cin >> n >> r;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (count(a.begin(), a.end(), 0) == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int st = n, ed = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            st = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            ed = i;
            break;
        }
    }

    st = min(st, r);
    ed = max(ed, r - 1);

    // cerr << st << " " << ed << endl;

    int ans = ed - st + 1;
    // cerr << ans << endl;
    for (int i = st; i <= ed; i++) {
        ans += a[i];
    }
    cout << ans << "\n";


    return 0;
}