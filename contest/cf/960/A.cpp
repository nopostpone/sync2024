#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int a[500];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int pos = 1;
    int cnt = 1;
    while (pos < n) {
        if (a[pos + 1] == a[pos])
            cnt++;
        else {
            if (cnt & 1) {
                cout << "yes" << endl;
                return;
            }
            cnt = 1;
        }
        pos++;
    }
    // 喜欢漏特判？
    // 喜欢漏特判？
    // 喜欢漏特判？
    if (cnt & 1) {
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}