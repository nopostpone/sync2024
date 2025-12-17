#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            a.push_back(i);
        }
    }
    cout << a.size() << " ";
    for (auto i : a) {
        cout << i + 1 << " ";
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