#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (int cnt = count(s.begin(), s.end(), '0'); cnt == 0 or (cnt == 1 and s.back() == '1')) {
        cout << -1 << "\n"; 
        return;
    }
    vector<int> cir, link = {0};

    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == '1') {
            link.push_back(i);
        } else {
            cir.push_back(i);
        }
    }
    link.push_back(n - 1);

    set<pair<int, int>> ans;
    for (int i = 0; i < (int)link.size() - 1; i++) {
        ans.emplace(link[i], link[i + 1]);
    }
    if (not cir.empty()) {
        ans.emplace(cir.front(), 0);
        ans.emplace(cir.back(), 0);
        for (int i= 0; i < (int)cir.size() - 1; i++) {
            ans.emplace(cir[i], cir[i + 1]);
        }
    }
    
    cout << ans.size() << "\n";
    for (auto [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << "\n";
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

/*
2
4
11
7
11000
*/