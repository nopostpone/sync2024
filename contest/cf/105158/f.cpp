#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    for (int _ = 0; _ < n; _++) {
        string s;
        cin >> s;

        if (s.size() != 5) {
            continue;
        }
        bool ok = true;

        string t = s.substr(0, 4);
        sort(t.begin(), t.end());
        for (int i = 1; i < 4; i++) {
            if (t[i] == t[i - 1]) {
                ok = false;
            }
        }

        if (s[2] != s[4]) {
            ok = false;
        }

        ans += ok;
    }

    cout << ans << "\n";
}

/*
4
henan
query
problem
queue
*/