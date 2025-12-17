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
        a[i]--;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[a[i]];
        b[a[i]]--;
    }

    bool par = 0;
    vector<bool> vis(n);
    for (int i = 0, j; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        j = i;
        bool len = 1;
        while (not vis[j]) {
            vis[j] = true;
            len ^= 1;
            j = b[j];
        }
        par ^= len;
    }

    string ans;
    auto work = [&]() {
        if (par % 2) {
            ans += 'A';
        } else {
            ans += 'B';
        }
    };
    work();
    
    for (int _ = 1; _ < n; _++) {
        char t;
        int l, r, d;
        cin >> t >> l >> r >> d;

        par ^= (i64)d * (r - l) & 1;
        work();
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}