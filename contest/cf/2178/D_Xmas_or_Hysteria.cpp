#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (m > n / 2) {
        cout << -1 << "\n";
        return;
    }
    
    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return a[i] < a[j];
    });
    vector<pair<int, int>> seq;
    if (m == 0) {
        i64 sum = 0;
        int i = 0;
        while (i < n - 2) {
            seq.emplace_back(ord[i], ord[n - 1]);
            sum += a[ord[i]];
            i++;
            if (sum >= a[ord[n - 1]] - a[ord[n - 2]]) {
                break;
            }
        }
        if (sum < a[ord[n - 1]] - a[ord[n - 2]]) {
            cout << -1 << "\n";
            return;
        }
        while (i < n - 1) {
            seq.emplace_back(ord[i + 1], ord[i]);
            i++;
        }
    } else {
        for (int i = 0; i + m < n; i++) {
            seq.emplace_back(ord[i + m], ord[i]);
        }
    }

    cout << seq.size() << "\n";
    for (auto [i, j] : seq) {
        cout << i + 1 << " " << j + 1 << "\n";
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