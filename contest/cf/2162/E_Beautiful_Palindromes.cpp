#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        vis[a[i]] = true;
    }

    vector<int> seq;
    if (ranges::count(vis, true) == n) {
        seq = {a[0], a[1], a[2]};
    } else {
        seq.push_back(find(vis.begin(), vis.end(), false) - vis.begin());
        for (int i = 0; i < n; i++) {
            if (i != a.back() and i != seq.front()) {
                seq.push_back(i);
                break;
            }
        }
        seq.push_back(a.back());
    }

    for (int i = 0; i < k; i++) {
        cout << seq[i % 3] + 1 << " \n"[i == k - 1];
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