#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(k), b(n - k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - k; i++) {
        cin >> b[i];
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> ans;

    int o = 0;
    while (not a.empty() and (not b.empty())) {
        if (o == 0) {
            ans.push_back(a.back());
            a.pop_back();
        } else {
            ans.push_back(b.back());
            b.pop_back();
        }
        o ^= 1;
    }
    if (not a.empty()) {
        reverse(a.begin(), a.end());
        for (auto x : a) {
            ans.push_back(x);
        }
    }
    if (not b.empty()) {
        reverse(b.begin(), b.end());
        for (auto x : b) {
            ans.push_back(x);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}