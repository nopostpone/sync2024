#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    string s;
    cin >> s;

    int o;
    cin >> o;

    vector a(4, vector<int>());

    const int n = s.size();
    bool flag{};
    int cur{};
    for (int i = 0; i < n; i++) {
        if (s[i] == '\'') {
            continue;
        }
        if (s[i] == '(') {
            flag = true;
            cur++;
        } else if (s[i] == ')') {
            cur--;
            flag = false;
        }
        if (not flag) {
            cur++;
        }
        if (s.substr(i, 2) == "L\'") {
            a[1].push_back(cur);
        } else if (s[i] == 'L') {
            a[0].push_back(cur);
        }
        if (s.substr(i, 2) == "R\'") {
            a[3].push_back(cur);
        } else if (s[i] == 'R') {
            a[2].push_back(cur);
        }
    }

    array<int, 4> ans{};
    for (int i = 0; i < 4; i++) {
        map<int, int> f;
        for (int j = 0; j < a[i].size(); j++) {
            a[i][j] -= j;
            f[a[i][j]]++;
        }
        for (auto [x, y] : f) {
            ans[i] = max(ans[i], y);
        }
    }

    cout << cur << "\n";
    if (o == 1) {
        for (auto i : ans) {
            cout << i << " ";
        }
    }

    return 0;
}