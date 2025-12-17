#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 2) {
        cout << 1 << endl;
        return;
    }

    int dis = 0;
    int lpos = n - 3;
    int rpos = n - 1;

    while (1) {
        if (s[lpos] == ')') {
            dis += rpos - lpos - 1;
            rpos = lpos;
        } else {
            dis++;
        }
        lpos -= 2;
        if (lpos < 0) {
            dis += rpos - lpos - 1;
            break;
        }
    }

    cout << dis << endl;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}