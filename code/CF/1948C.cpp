#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 有关曼哈顿距离的 trick

void solve() {
    int n;
    cin >> n;

    vector<string> s(2);
    for (int i : {0, 1}) {
        cin >> s[i];
    }

    bool lst{}, ok{true};
    for (int i = 0; i < n; i++) {
        int j = not (i & 1);
        if (s[j][i] == '<') {
            if (lst == true) {
                ok = false;
            } else {
                lst = true;
            }
        } else {
            lst = false;
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