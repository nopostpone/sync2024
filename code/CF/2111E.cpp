#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector f(3, vector<set<int>>(3));
    for (int i = 0; i < q; i++) {
        char x, y;
        cin >> x >> y;
        f[x - 'a'][y - 'a'].insert(i);
    }

    auto popFront = [](set<int> &s) {
        s.erase(s.begin());
    };

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            continue;
        }
        if (s[i] == 'b') {
            if (not f[1][0].empty()) {
                popFront(f[1][0]);
                s[i] = 'a';

            } else if (not f[1][2].empty()) {

                int p = *f[1][2].begin();
                auto it = f[2][0].lower_bound(p);
                if (it != f[2][0].end()) {
                    popFront(f[1][2]);
                    f[2][0].erase(it);
                    s[i] = 'a';
                }
            }

        } else {

            if (not f[2][0].empty()) {
                popFront(f[2][0]);
                s[i] = 'a';

            } else if (not f[2][1].empty()) {

                int p = *f[2][1].begin();
                popFront(f[2][1]);
                s[i] = 'b';

                auto it = f[1][0].lower_bound(p);
                if (it != f[1][0].end()) {
                    f[1][0].erase(it);
                    s[i] = 'a';
                }
            }
        }
    }
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}