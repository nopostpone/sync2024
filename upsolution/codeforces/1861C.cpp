#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    const int n = s.size();

    int cnt{}, sorted{}, unsorted{};
    bool ok{true};
    for (int i = 0; i < n and ok; i++) {
        if (s[i] == '+') {
            cnt++;
        } else if (s[i] == '-') {
            cnt--;
            sorted = min(sorted, cnt);
            if (unsorted > cnt) {
                unsorted = 0;
            }
        } else if (s[i] == '0') {
            if (cnt < 2 or sorted == cnt) {
                ok = false;
            } else if (unsorted == 0) {
                unsorted = cnt;
            }
        } else {
            if (unsorted != 0) {
                ok = false;
            } else {
                sorted = cnt;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}