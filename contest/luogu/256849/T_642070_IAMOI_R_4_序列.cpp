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
    vector<int> todo;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[i] == -1) {
            todo.push_back(i);
        }
    }

    
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