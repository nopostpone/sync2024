#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;
constexpr int mod = 1e9 + 7;

int cnt;
int n;
vector<vector<int>> res;

void dfs(int dep, int sum, vector<int> v) {
    if (dep == 10) {
        if (sum == n) {
            cnt++;
            res.push_back(v);
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        vector<int> tmp = v;
        tmp.push_back(i);
        dfs(dep + 1, sum + i, tmp);
    }
}

void solve() {
    cin >> n;
    if (n < 10 or n > 30) {
        cout << 0;
        return;
    }
    dfs(0, 0, {});
    cout << cnt << "\n";
    for (auto &v : res) {
        for (auto &i : v) {
            cout << i << ' ';
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}