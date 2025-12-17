#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    char x;
    vector<int> a[2];
    for (int i : {0, 1}) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            assert(x == 'x' or x == '.');
            if (x == 'x')
                a[i].push_back(0);
            else
                a[i].push_back(1);
        }
    }
    int cnt = 0;

    for (int i = 1; i < n - 1; i++) {
        if (a[1][i - 1] and a[1][i] and a[1][i + 1] and
            !a[0][i - 1] and a[0][i] and !a[0][i + 1]) {
            cnt++;
        } else if (!a[1][i - 1] and a[1][i] and !a[1][i + 1] and
                   a[0][i - 1] and a[0][i] and a[0][i + 1]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}