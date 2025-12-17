#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    array<string, 2> s;
    cin >> s[0] >> s[1];

    for (int i : {0, 1}) {
        s[i] = 'x' + s[i];
        s[i] += 'x';
    }

    // cerr << s[0] << "\n"
    //      << s[1] << endl;

    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int u : {0, 1}) {
            if (s[u][i] != '.') {
                continue;
            }
            bool ok = false;
            int v = u ^ 1;
            bool a = s[u][i - 1] == '.';
            bool b = s[u][i + 1] == '.';
            bool c = s[v][i] == '.';
            bool d = s[v][i - 1] == '.';
            bool e = s[v][i + 1] == '.';
            if (not (a or b or c)) {
                ok = true;
            } else {
                if (a and b and not (c and d and e)) {
                    ok = true;
                }
                if (a and c and not d) {
                    ok = true;
                }
                if (b and c and not e) {
                    ok = true;
                }
            }
            ans += ok;
        }
        // cerr << i << " " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}