#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> res;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<vector<int>> fa(n, vector<int>(26, 0));
    vector<vector<int>> fb(n, vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        a[i] = x - 'a';
    }
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        b[i] = x - 'a';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            fa[i][j] = fa[i - 1 == -1 ? 0 : i - 1][j] + (a[i] == j);
            fb[i][j] = fb[i - 1 == -1 ? 0 : i - 1][j] + (b[i] == j);
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        int tmp = 0;
        l--, r--;
        for (int i = 0; i < 26; i++) {
            if (l == 0) {
                tmp += abs(fa[r][i] - fb[r][i]);
            } else
                tmp += abs(fa[r][i] - fa[l - 1][i] - fb[r][i] + fb[l - 1][i]);
        }        
        res.push_back(tmp >> 1);
    }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}