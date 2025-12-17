#include <bits/stdc++.h>

using namespace std;

auto solve() {
    int st;
    cin >> st;

    int n;
    cin >> n;
    
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ed;
    cin >> ed;

    int ans = ed - st + 1;
    for (auto x : s) {
        if (st <= x and x <= ed) {
            ans--;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

/*
4
2003
1 2020
2023
2003
1 2020
2003
2345
0
3456
3000
4 3001 3003 3004 3008
3007
*/